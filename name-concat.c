#include <gtk/gtk.h>

struct EntryList {
  GtkWidget *entry_first;
  GtkWidget *entry_last;
};

static void
combine (GtkWidget *button,
         gpointer   user_data)
{
  struct EntryList *entries = user_data;

  const char *first, *last;
  first = gtk_entry_get_text(GTK_ENTRY(entries->entry_first));
  last = gtk_entry_get_text(GTK_ENTRY(entries->entry_last));

  g_print("\nHello %s %s!\n\n", first, last);
}

static void
activate (GtkApplication *main_app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *label_first;
  GtkWidget *label_last;
  struct EntryList *entries = malloc(sizeof(GtkWidget *) * 2);
  GtkWidget *button;

  /* create window, set title, set size, set width */
  window = gtk_application_window_new(main_app);
  gtk_window_set_title(GTK_WINDOW(window), "Combine Names");
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 300);
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  /* create label(s) */
  label_first = gtk_label_new("First Name:");
  label_last = gtk_label_new("Last Name:");

  /* create entry(s) */
  entries->entry_first = gtk_entry_new();
  entries->entry_last = gtk_entry_new();

  /* create button */
  button = gtk_button_new_with_label("Combine!");

  /* create grid */
  grid = gtk_grid_new();
  gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
  gtk_grid_attach(GTK_GRID(grid), label_first, 1, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), label_last, 1, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), entries->entry_first, 2, 1, 2, 1);
  gtk_grid_attach(GTK_GRID(grid), entries->entry_last, 2, 2, 2, 1);
  gtk_grid_attach(GTK_GRID(grid), button, 1, 3, 3, 1);

  g_signal_connect(GTK_BUTTON(button), "clicked",
                   G_CALLBACK(combine), entries);
  gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(grid));
  gtk_widget_show_all(window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *main_app;
  int status;

  main_app = gtk_application_new(NULL, G_APPLICATION_FLAGS_NONE);
  g_signal_connect(main_app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(main_app), argc, argv);
  g_object_unref(main_app);

  return status;
}
