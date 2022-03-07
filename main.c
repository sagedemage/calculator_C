#include <gtk/gtk.h>
#include "defs.h"
#include <string.h>

double num1 = 0;
double num2 = 0;
double solution = 0;
char operation = 'n';
GtkEntryBuffer* buffer;
char text[] = "";


static void set_number (GtkWidget *widget, gint data) {
	sprintf(text,"%d",data);
	if (operation == 'n') {
		num1 = data;
		gtk_entry_buffer_set_text(buffer, text, -1);
	}
	else {
		num2 = data;
		gtk_entry_buffer_insert_text(buffer, 2, text, -1);
	}
	g_print("%i", data);
	g_print(" ");
}

static void set_operation (GtkWidget *widget, gchar data) {
	operation = data;
	if (operation == ADDITION) {
		gtk_entry_buffer_insert_text(buffer, 1, "+", -1);
	}
	if (operation == SUBTRACTION) {
		gtk_entry_buffer_insert_text(buffer, 1, "-", -1);
	}
	if (operation == MULTIPLICATION) {
		gtk_entry_buffer_insert_text(buffer, 1, "*", -1);
	}
	if (operation == DIVISION) {
		gtk_entry_buffer_insert_text(buffer, 1, "/", -1);
	}
}

static void result(GtkWidget *widget, gpointer data) {
	if (operation == ADDITION) {
		solution = num1 + num2;
	}
	if (operation == SUBTRACTION) {
		solution = num1 - num2;
	}
	if (operation == MULTIPLICATION) {
		solution = num1 * num2;
	}
	if (operation == DIVISION) {
		solution = num1 / num2;
	}
	sprintf(text,"%f",solution);
	gtk_entry_buffer_set_text(buffer, text, -1);

	num1 = 0;
	num2 = 0;
	solution = 0;
	operation = 'n';
}

static void activate (GtkApplication *app, gpointer user_data) {
	/* GUI Widgets */
	GtkWidget *window, *grid, *button, *entry;
	GtkGrid *grid2;
	// Scaling 
	static int wid = 2; // width
	static int hei = 2; // height
	static int row1 = 0;
	static int row2 = 2;
	static int row3 = 4;
	static int row4 = 6;
	static int row5 = 8;
	static int row6 = 10;
	static int row7 = 12;

	static int col1 = 0;
	static int col2 = 2;
	static int col3 = 4;
	static int col4 = 6;

	/* Create Entry Buffer object */
	buffer = gtk_entry_buffer_new("", -1);

	/* Create window and set its title */
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW (window), "    Calculator    ");

	gtk_window_set_default_size(GTK_WINDOW(window), WINDOW_WIDTH, WINDOW_HEIGHT); //Set window size
	gtk_window_set_resizable (GTK_WINDOW(window), FALSE);

	/* Here we construct the container that is going pack our buttons */
	grid = gtk_grid_new();

	/* Pack the container in the window */
	gtk_window_set_child(GTK_WINDOW(window), grid); // add the grid in the window

	/* Display the output of the calculation */
	/* row 1 */
	entry = gtk_entry_new_with_buffer(buffer);
	gtk_grid_attach(GTK_GRID(grid), entry, col1, row1, 8, 1);

	/* Set button label, action, and location */
	/* row 7 */
	button = gtk_button_new_with_label("Quit");
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), window);
	gtk_grid_attach(GTK_GRID(grid), button, col1, row7, 6, 1);

	/* row 6 */
	button = gtk_button_new_with_label("0");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)0);
	gtk_grid_attach(GTK_GRID(grid), button, col2, row6, wid, hei);

	button = gtk_button_new_with_label("=");
	g_signal_connect(button, "clicked", G_CALLBACK(result), NULL);
	gtk_grid_attach(GTK_GRID(grid), button, col4, row6, wid, hei);

	/* row 5 */
	button = gtk_button_new_with_label("1");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)1);
	gtk_grid_attach(GTK_GRID(grid), button, col1, row5, wid, hei);

	button = gtk_button_new_with_label("2");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)2);
	gtk_grid_attach(GTK_GRID(grid), button, col2, row5, wid, hei);

	button = gtk_button_new_with_label("3");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)3);
	gtk_grid_attach(GTK_GRID(grid), button, col3, row5, wid, hei);

	button = gtk_button_new_with_label("+");
	g_signal_connect(button, "clicked", G_CALLBACK(set_operation), (void *)'a');
	gtk_grid_attach(GTK_GRID(grid), button, col4, row5, wid, hei);

	/* row 4 */
	button = gtk_button_new_with_label("4");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)4);
	gtk_grid_attach(GTK_GRID(grid), button, col1, row4, wid, hei);

	button = gtk_button_new_with_label("5");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)5);
	gtk_grid_attach(GTK_GRID(grid), button, col2, row4, wid, hei);

	button = gtk_button_new_with_label("6");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)6);
	gtk_grid_attach(GTK_GRID(grid), button, col3, row4, wid, hei);

	button = gtk_button_new_with_label("-");
	g_signal_connect(button, "clicked", G_CALLBACK(set_operation), (void *)'s');
	gtk_grid_attach(GTK_GRID(grid), button, col4, row4, wid, hei);

	/* row 3 */
	button = gtk_button_new_with_label("7");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)7);
	gtk_grid_attach(GTK_GRID(grid), button, col1, row3, wid, hei);

	button = gtk_button_new_with_label("8");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)8);
	gtk_grid_attach(GTK_GRID(grid), button, col2, row3, wid, hei);

	button = gtk_button_new_with_label("9");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)9);
	gtk_grid_attach(GTK_GRID(grid), button, col3, row3, wid, hei);

	button = gtk_button_new_with_label("*");
	g_signal_connect(button, "clicked", G_CALLBACK(set_operation), (void *)'m');
	gtk_grid_attach(GTK_GRID(grid), button, col4, row3, wid, hei);

	/* row 2 */
	button = gtk_button_new_with_label("/");
	g_signal_connect(button, "clicked", G_CALLBACK(set_operation), (void *)'d');
	gtk_grid_attach(GTK_GRID(grid), button, col4, row2, wid, hei);

	gtk_widget_show(window); // Display window
}

int main(int argc, char **argv) {
	GtkApplication *app;
	int status;

	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE); // pick application identifier and set flags
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL); // activate the activate function 
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app); // free memory of the application

	return status;
}
