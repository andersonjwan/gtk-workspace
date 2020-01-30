#include <gtk/gtk.h>

static void
first_number (GtkButton *button_num,
          gpointer   user_data)
{
  GtkEntry *entry = GTK_ENTRY(user_data);
  char number = *(gtk_button_get_label(GTK_BUTTON(button_num)) + 0);

  printf("%c", number);

  switch(number) {
  case '0': {
    gtk_entry_set_text(GTK_ENTRY(entry), "0");
  }
    break;
  case '1': {
    gtk_entry_set_text(GTK_ENTRY(entry), "1");
  }
    break;
  case '2': {
    gtk_entry_set_text(GTK_ENTRY(entry), "2");
  }
    break;
  case '3': {
    gtk_entry_set_text(GTK_ENTRY(entry), "3");
  }
    break;
  case '4': {
    gtk_entry_set_text(GTK_ENTRY(entry), "4");
  }
    break;
  case '5': {
    gtk_entry_set_text(GTK_ENTRY(entry), "5");
  }
    break;
  case '6': {
    gtk_entry_set_text(GTK_ENTRY(entry), "6");
  }
    break;
  case '7': {
    gtk_entry_set_text(GTK_ENTRY(entry), "7");
  }
    break;
  case '8': {
    gtk_entry_set_text(GTK_ENTRY(entry), "8");
  }
    break;
  case '9': {
    gtk_entry_set_text(GTK_ENTRY(entry), "9");
  }
    break;
  }
}

static void
activate (GtkApplication *main_app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *entry;
  GtkWidget *button_plus;
  GtkWidget *button_0;
  GtkWidget *button_1;
  GtkWidget *button_2;
  GtkWidget *button_3;
  GtkWidget *button_4;
  GtkWidget *button_5;
  GtkWidget *button_6;
  GtkWidget *button_7;
  GtkWidget *button_8;
  GtkWidget *button_9;
  GtkWidget *button_equal;

  /* create window, set title, set size, set border width */
  window = gtk_application_window_new(main_app);
  gtk_window_set_title(GTK_WINDOW(window), "Simple Calculator");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  /* create grid */
  grid = gtk_grid_new();
  gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
  gtk_grid_set_column_spacing(GTK_GRID(grid), 5);

  /* create entry and attach to grid */
  entry = gtk_entry_new();
  gtk_grid_attach(GTK_GRID(grid), entry, 1, 1, 3, 1);

  /* create buttons and attach to grid */
  button_0 = gtk_button_new_with_label("0");
  button_1 = gtk_button_new_with_label("1");
  button_2 = gtk_button_new_with_label("2");
  button_3 = gtk_button_new_with_label("3");
  button_4 = gtk_button_new_with_label("4");
  button_5 = gtk_button_new_with_label("5");
  button_6 = gtk_button_new_with_label("6");
  button_7 = gtk_button_new_with_label("7");
  button_8 = gtk_button_new_with_label("8");
  button_9 = gtk_button_new_with_label("9");
  button_plus = gtk_button_new_with_label("+");
  button_equal= gtk_button_new_with_label("=");

  gtk_grid_attach(GTK_GRID(grid), button_9, 3, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_8, 2, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_7, 1, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_6, 3, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_5, 2, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_4, 1, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_3, 3, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_2, 2, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_1, 1, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_0, 2, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_plus, 1, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_equal, 3, 5, 1, 1);

  /* button conection(s) */
  g_signal_connect(button_0, "clicked", G_CALLBACK(first_number), entry);
  g_signal_connect(button_1, "clicked", G_CALLBACK(first_number), entry);
  g_signal_connect(button_2, "clicked", G_CALLBACK(first_number), entry);
  g_signal_connect(button_3, "clicked", G_CALLBACK(first_number), entry);
  g_signal_connect(button_4, "clicked", G_CALLBACK(first_number), entry);
  g_signal_connect(button_5, "clicked", G_CALLBACK(first_number), entry);
  g_signal_connect(button_6, "clicked", G_CALLBACK(first_number), entry);
  g_signal_connect(button_7, "clicked", G_CALLBACK(first_number), entry);
  g_signal_connect(button_8, "clicked", G_CALLBACK(first_number), entry);
  g_signal_connect(button_9, "clicked", G_CALLBACK(first_number), entry);
  g_signal_connect(button_plus, "clicked", G_CALLBACK(first_number), entry);
  g_signal_connect(button_equal, "clicked", G_CALLBACK(first_number), entry);
  gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(grid));
  gtk_widget_show_all(window);
}

int
main(int argc,
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
