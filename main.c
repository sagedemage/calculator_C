#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include "defs.h"

int num1 = 0;
int num2 = 0;
int solution = 0;
char operation = 'n';


static void print_hello (GtkWidget *widget, gpointer data) {
	g_print("Welcome aliens!\n"); // Print output in the terminal
}

static void set_number (GtkWidget *widget, gpointer data) {
	if (operation == 'n') {
		num1 = 1;
	}
	else {
		num2 = 1;
	}
}

static void set_operation (GtkWidget *widget, gpointer data) {
	operation = ADDITION;
}

static void result(GtkWidget *widget, gpointer data) {
	if (operation == ADDITION) {
		solution = num1 + num2;
	}
	g_print("%i", solution);
	g_print("\n");

	num1 = 0;
	num2 = 0;
	solution = 0;
	operation = 'n';
}

static void activate (GtkApplication *app, gpointer user_data) {
	GtkWidget *window; //dereference window
	GtkWidget *grid; 
	GtkWidget *button; //dereference button

	/* Create window and set its title */
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW (window), "Calculator");

	gtk_window_set_default_size(GTK_WINDOW(window), WINDOW_WIDTH, WINDOW_HEIGHT); //Set window size

	/* Here we construct the container that is going pack our buttons */
	grid = gtk_grid_new();

	/* Pack the container in the window */
	gtk_window_set_child(GTK_WINDOW(window), grid); // add the grid in the window

	/* Set button label and action */
	button = gtk_button_new_with_label("1");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), NULL); // Connect the button to an action
	
	/* Place the first button in the grid cell (0, 0), and make it fill
    * just 1 cell horizontally and vertically (ie no spanning)
    */
	gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);

	/* Set button label and action */
	button = gtk_button_new_with_label("2");
	g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL); // Connect the button to an action
	
	/* Place the first button in the grid cell (0, 0), and make it fill
    * just 1 cell horizontally and vertically (ie no spanning)
    */
	gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);

	button = gtk_button_new_with_label("+");
	g_signal_connect(button, "clicked", G_CALLBACK(set_operation), NULL); // Connect the button to an action

	/* Place the second button in the grid cell (1, 0), and make it fill
   * just 1 cell horizontally and vertically (ie no spanning)
   */
	gtk_grid_attach(GTK_GRID(grid), button, 1, 0, 1, 1);

	button = gtk_button_new_with_label("=");
	g_signal_connect(button, "clicked", G_CALLBACK(result), NULL); // Connect the button to an action

	/* Place the second button in the grid cell (1, 0), and make it fill
   * just 1 cell horizontally and vertically (ie no spanning)
   */
	gtk_grid_attach(GTK_GRID(grid), button, 1, 1, 1, 1);

	button = gtk_button_new_with_label("Quit");
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), window);

	/* Place the Quit button in the grid cell (0, 1), and make it
   * span 2 columns.
   */
	gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 2, 1);
	gtk_widget_show(window);
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
