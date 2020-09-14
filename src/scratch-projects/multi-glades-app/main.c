#include <gtk/gtk.h>

static GtkBuilder *new = NULL;
static GtkBuilder *old = NULL;

void
print_results(void)
{
  fprintf(stdout, "Old: %p, New: %p\n", old, new);
  return;
}

void
popup(GtkButton *button,
      gpointer   data)
{
  print_results();
  GtkBuilder *builder;
  builder = gtk_builder_new_from_file("./popup.ui");
  gtk_builder_connect_signals(GTK_BUILDER(builder), data);

  /* setup popup window */
  GtkWidget *window;
  window = GTK_WIDGET(gtk_builder_get_object(GTK_BUILDER(builder), "main-dialog"));

  gtk_widget_show_all(GTK_WIDGET(window));

  old = new;
  new = builder;

  return;
}

void
activate(GtkApplication *app,
         gpointer        data)
{
  GtkBuilder *builder;
  GtkWidget  *window;

  /* init builder */
  builder = gtk_builder_new_from_file("./main.ui");
  gtk_builder_connect_signals(GTK_BUILDER(builder), data);

  /* set app window */
  window  = GTK_WIDGET(gtk_builder_get_object(GTK_BUILDER(builder), "main-window"));
  gtk_application_add_window(GTK_APPLICATION(app), GTK_WINDOW(window));

  /* display application */
  gtk_widget_show_all(GTK_WIDGET(window));

  return;
}

int
main(int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new("com.github.andersonjwan.multi-glade-app",
                            G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
