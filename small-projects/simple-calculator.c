#include <gtk/gtk.h>

static void
insert_number (GtkButton *button_num,
          gpointer   user_data)
{
  GtkEntry *entry = GTK_ENTRY(user_data);
  char number = *(gtk_button_get_label(GTK_BUTTON(button_num)) + 0);
  char result[100];
  strcpy(result, gtk_entry_get_text(GTK_ENTRY(entry)));

  switch(number) {
  case '0': {
    strcat(result, "0");
    gtk_entry_set_text(GTK_ENTRY(entry), result);
  }
    break;
  case '1': {
    strcat(result, "1");
    gtk_entry_set_text(GTK_ENTRY(entry), result);
  }
    break;
  case '2': {
    strcat(result, "2");
    gtk_entry_set_text(GTK_ENTRY(entry), result);
  }
    break;
  case '3': {
    strcat(result, "3");
    gtk_entry_set_text(GTK_ENTRY(entry), result);
  }
    break;
  case '4': {
    strcat(result, "4");
    gtk_entry_set_text(GTK_ENTRY(entry), result);
  }
    break;
  case '5': {
    strcat(result, "5");
    gtk_entry_set_text(GTK_ENTRY(entry), result);
  }
    break;
  case '6': {
    strcat(result, "6");
    gtk_entry_set_text(GTK_ENTRY(entry), result);
  }
    break;
  case '7': {
    strcat(result, "7");
    gtk_entry_set_text(GTK_ENTRY(entry), result);
  }
    break;
  case '8': {
    strcat(result, "8");
    gtk_entry_set_text(GTK_ENTRY(entry), result);
  }
    break;
  case '9': {
    strcat(result, "9");
    gtk_entry_set_text(GTK_ENTRY(entry), result);
  }
    break;
  case '+': {
    strcat(result, "+");
    gtk_entry_set_text(GTK_ENTRY(entry), result);
  }
    break;
  case '-': {
    strcat(result, "-");
    gtk_entry_set_text(GTK_ENTRY(entry), result);
  }
  }
}

static void
calculate_sum(GtkButton *button_plus,
              gpointer  user_data)
{
  GtkEntry *entry = GTK_ENTRY(user_data);

  /* parse entry into respective values */
  int sum = 0;
  int num, pos = 0;
  char character;
  char input[100];

  strcpy(input, gtk_entry_get_text(GTK_ENTRY(entry)));
  character = input[pos];

  while(character != '\0') {
    char temp_num[100];
    int temp_pos = 0;

    while(character != '+' && character != '-' && character != '\0') {
      temp_num[temp_pos] = character;
      ++temp_pos;

      /* look at next character */
      ++pos;
      character = input[pos];
    }

    /* append null terminating character */
    temp_num[temp_pos] = '\0';

    printf("NUM: %s\n", temp_num);
    /* determine sum or difference */
    if(character == '+') {
      printf("PLUS\n");
      sum += atoi(temp_num);
    }
    else if(character == '-') {
      printf("MINUS\n");
      sum -= atoi(temp_num);
    }

    printf("CURRENT SUM: %d\n", sum);
    /* read after plus symbol */
    if(character != '\0') {
      ++pos;
      character = input[pos];
    }
  }

  /* set sum result */
  char result[100];

  sprintf(result, "%d", sum);
  gtk_entry_set_text(entry, result);
}

static void
clear_entry(GtkButton *button_clear,
            gpointer   user_data)
{
  GtkEntry *entry = GTK_ENTRY(user_data);
  gtk_entry_set_text(entry, "");
}

static void
activate (GtkApplication *main_app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *entry;
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
  GtkWidget *button_plus;
  GtkWidget *button_minus;
  GtkWidget *button_equal;
  GtkWidget *button_clear;

  /* create window, set title, set size, set border width */
  window = gtk_application_window_new(main_app);
  gtk_window_set_title(GTK_WINDOW(window), "Simple Calculator");
  gtk_window_set_default_size(GTK_WINDOW(window), 100, 100);
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  /* create grid */
  grid = gtk_grid_new();
  gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
  gtk_grid_set_column_spacing(GTK_GRID(grid), 5);

  /* create entry and attach to grid */
  entry = gtk_entry_new();
  gtk_entry_set_alignment(GTK_ENTRY(entry), 1);
  gtk_grid_attach(GTK_GRID(grid), entry, 1, 1, 4, 1);

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
  button_minus = gtk_button_new_with_label("-");
  button_equal= gtk_button_new_with_label("=");
  button_clear = gtk_button_new_with_label("C");

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
  gtk_grid_attach(GTK_GRID(grid), button_minus, 3, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_clear, 4, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_equal, 4, 3, 1, 3);

  /* button conection(s) */
  g_signal_connect(button_0, "clicked", G_CALLBACK(insert_number), entry);
  g_signal_connect(button_1, "clicked", G_CALLBACK(insert_number), entry);
  g_signal_connect(button_2, "clicked", G_CALLBACK(insert_number), entry);
  g_signal_connect(button_3, "clicked", G_CALLBACK(insert_number), entry);
  g_signal_connect(button_4, "clicked", G_CALLBACK(insert_number), entry);
  g_signal_connect(button_5, "clicked", G_CALLBACK(insert_number), entry);
  g_signal_connect(button_6, "clicked", G_CALLBACK(insert_number), entry);
  g_signal_connect(button_7, "clicked", G_CALLBACK(insert_number), entry);
  g_signal_connect(button_8, "clicked", G_CALLBACK(insert_number), entry);
  g_signal_connect(button_9, "clicked", G_CALLBACK(insert_number), entry);

  g_signal_connect(button_plus, "clicked", G_CALLBACK(insert_number), entry);
  g_signal_connect(button_minus, "clicked", G_CALLBACK(insert_number), entry);
  g_signal_connect(button_equal, "clicked", G_CALLBACK(calculate_sum), entry);
  g_signal_connect(button_clear, "clicked", G_CALLBACK(clear_entry), entry);

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
