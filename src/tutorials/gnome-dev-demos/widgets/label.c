/**
 * Gnome Developer Demos
 *
 * Tutorial Permalink:
 * https://developer.gnome.org/gnome-devel-demos/stable/label.c.html.en
 */
#include <gtk/gtk.h>

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *label;

  /* create a window with a title and a default size */
  window = gtk_application_window_new(app);
  gtk_window_set_application(GTK_WINDOW(window), GTK_APPLICATION(app));
  gtk_window_set_title(GTK_WINDOW(window), "Label Demo");
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

  /* create a label and set its alignment */
  label = gtk_label_new("Hello GNOME Label. Hello GNOME Label.");
  gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_CENTER);
  gtk_label_set_line_wrap(GTK_LABEL(label), TRUE);

  /* place widget in container */
  gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(label));
  gtk_widget_show_all(GTK_WIDGET(window));
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new(NULL, G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
