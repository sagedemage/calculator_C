#include <gtk/gtk.h>
#include "defs.h"

double num1 = 0;
double num2 = 0;
double solution = 0;
char operation = 'n';
GtkEntryBuffer* buffer;

static void set_number (GtkWidget *widget, gint data) {
	// string converison 
	char op[] = "";
	sprintf(op,"%d",data);

	if (operation == 'n' && num1 == 0) {
		/* Set a value for the first number */
		num1 = data;
		gtk_entry_buffer_set_text(buffer, op, -1);
	}
	else if (operation != 'n' && num2 == 0) {
		/* Set a value for the second number */
		num2 = data;
		gtk_entry_buffer_insert_text(buffer, 2, op, -1);
	}
}

static void set_operation (GtkWidget *widget, gchar data) {
	if (operation == 'n') {
		operation = data;
		if (operation == ADDITION) {
			/* Show addition symbol on the buffer */
			gtk_entry_buffer_insert_text(buffer, 1, "+", -1);
		}
		if (operation == SUBTRACTION) {
			/* Show substraction symbol on the buffer */
			gtk_entry_buffer_insert_text(buffer, 1, "-", -1);
		}
		if (operation == MULTIPLICATION) {
			/* Show the multiplication symbol on the buffer */
			gtk_entry_buffer_insert_text(buffer, 1, "*", -1);
		}
		if (operation == DIVISION) {
			/* Show the division symbol on the buffer */
			gtk_entry_buffer_insert_text(buffer, 1, "/", -1);
		}
	}
}

static void result(GtkWidget *widget, gpointer data) {
	if (operation == ADDITION) {
		/* Result of additon */
		solution = num1 + num2;
	}
	if (operation == SUBTRACTION) {
		/* Result of substraction */
		solution = num1 - num2;
	}
	if (operation == MULTIPLICATION) {
		/* Result of multiplication */
		solution = num1 * num2;
	}
	if (operation == DIVISION) {
		/* Result of division */
		solution = num1 / num2;
	}

	// string converison 
	char sol[] = "none";
	sprintf(sol,"%f",solution);

	gtk_entry_buffer_set_text(buffer, sol, -1);

	num1 = 0;
	num2 = 0;
	solution = 0;
	operation = 'n';
}

static void activate (GtkApplication *app, gpointer user_data) {
	/* GUI Widgets */
	GtkWidget *window, *grid, *button, *entry;

	/* Create Entry Buffer object */
	buffer = gtk_entry_buffer_new("", -1);

	/* Create window and set its title */
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW (window), "Calculator");

	gtk_window_set_default_size(GTK_WINDOW(window), WINDOW_WIDTH, WINDOW_HEIGHT); //Set window size

	/* Here we construct the container that is going pack our buttons */
	grid = gtk_grid_new();

	/* Pack the container in the window */
	gtk_window_set_child(GTK_WINDOW(window), grid); // add the grid in the window

	/* Display the output of the calculation */
	entry = gtk_entry_new_with_buffer(buffer);
	gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 4, 1);

	/* Set button label, action, and location */
	/* row 5 */
	button = gtk_button_new_with_label("0");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)0);
	gtk_grid_attach(GTK_GRID(grid), button, 1, 5, 1, 1);

	button = gtk_button_new_with_label("=");
	g_signal_connect(button, "clicked", G_CALLBACK(result), NULL);
	gtk_grid_attach(GTK_GRID(grid), button, 3, 5, 1, 1);

	/* row 4 */
	button = gtk_button_new_with_label("1");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)1);
	gtk_grid_attach(GTK_GRID(grid), button, 0, 4, 1, 1);

	button = gtk_button_new_with_label("2");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)2);
	gtk_grid_attach(GTK_GRID(grid), button, 1, 4, 1, 1);

	button = gtk_button_new_with_label("3");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)3);
	gtk_grid_attach(GTK_GRID(grid), button, 2, 4, 1, 1);

	button = gtk_button_new_with_label("+");
	g_signal_connect(button, "clicked", G_CALLBACK(set_operation), (void *)'a');
	gtk_grid_attach(GTK_GRID(grid), button, 3, 4, 1, 1);

	/* row 3 */
	button = gtk_button_new_with_label("4");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)4);
	gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 1, 1);

	button = gtk_button_new_with_label("5");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)5);
	gtk_grid_attach(GTK_GRID(grid), button, 1, 3, 1, 1);

	button = gtk_button_new_with_label("6");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)6);
	gtk_grid_attach(GTK_GRID(grid), button, 2, 3, 1, 1);

	button = gtk_button_new_with_label("-");
	g_signal_connect(button, "clicked", G_CALLBACK(set_operation), (void *)'s');
	gtk_grid_attach(GTK_GRID(grid), button, 3, 3, 1, 1);

	/* row 2 */
	button = gtk_button_new_with_label("7");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)7);
	gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 1, 1);

	button = gtk_button_new_with_label("8");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)8);
	gtk_grid_attach(GTK_GRID(grid), button, 1, 2, 1, 1);

	button = gtk_button_new_with_label("9");
	g_signal_connect(button, "clicked", G_CALLBACK(set_number), (void *)9);
	gtk_grid_attach(GTK_GRID(grid), button, 2, 2, 1, 1);

	button = gtk_button_new_with_label("*");
	g_signal_connect(button, "clicked", G_CALLBACK(set_operation), (void *)'m');
	gtk_grid_attach(GTK_GRID(grid), button, 3, 2, 1, 1);

	/* Set button label, action, and location */
	button = gtk_button_new_with_label("/");
	g_signal_connect(button, "clicked", G_CALLBACK(set_operation), (void *)'d');
	gtk_grid_attach(GTK_GRID(grid), button, 3, 1, 1, 1);

	button = gtk_button_new_with_label("Quit");
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), window);
	gtk_grid_attach(GTK_GRID(grid), button, 0, 6, 3, 1);

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
