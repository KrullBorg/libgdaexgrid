/*
 * Copyright (C) 2016 Andrea Zagli <azagli@libero.it>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <libgdaex/libgdaex.h>

#include "grid.h"
#include "gridcolumn.h"

int
main (int argc, char **argv)
{
	GtkWidget *w;
	GtkWidget *vbox;
	GtkWidget *scrolledw;

	GdaExGrid *grid;
	GdaExGridColumn *gcol;
	GtkWidget *wgrid;

	GtkTreeIter iter;
	GtkTreeIter parent;
	GtkTreeStore *tstore;

	gtk_init (&argc, &argv);

	w = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW (w), 550, 350);
	g_signal_connect (w, "delete-event",
	                  G_CALLBACK (gtk_false), NULL);
	g_signal_connect (w, "destroy",
	                  G_CALLBACK (gtk_main_quit), NULL);

	vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add (GTK_CONTAINER (w), vbox);

	scrolledw = gtk_scrolled_window_new (NULL, NULL);
	gtk_box_pack_start (GTK_BOX (vbox), scrolledw, TRUE, TRUE, 0);

	grid = gdaex_grid_new ();
	gdaex_grid_set_title (grid, "The grid title");

#ifdef SOLIPA_FOUND
	gdaex_grid_set_solipa (grid, solipa_new ());
#endif

	gcol = gdaex_grid_column_new ("ID", "id", G_TYPE_INT, TRUE, FALSE, FALSE, FALSE, -1);
	gdaex_grid_add_column (grid, gcol);

	gcol = gdaex_grid_column_new ("Name", "name", G_TYPE_STRING, TRUE, TRUE, TRUE, TRUE, -1);
	gdaex_grid_add_column (grid, gcol);

	gcol = gdaex_grid_column_new_defaults ("Surname", "surname", G_TYPE_STRING);
	gdaex_grid_add_column (grid, gcol);

	gcol = gdaex_grid_column_new_defaults ("Incoming", "incoming", G_TYPE_DOUBLE);
	gdaex_grid_add_column (grid, gcol);

	wgrid = gdaex_grid_get_widget (grid);
	gtk_container_add (GTK_CONTAINER (scrolledw), wgrid);

	tstore = GTK_TREE_STORE (gtk_tree_view_get_model (GTK_TREE_VIEW (wgrid)));

	gtk_tree_store_append (tstore, &parent, NULL);
	gtk_tree_store_set (tstore, &parent,
						   0, 1,
						   1, "Jon",
						   2, "Do",
						   -1);
	gtk_tree_store_append (tstore, &iter, &parent);
	gtk_tree_store_set (tstore, &iter,
						   3, "1234,55",
						   -1);
	gtk_tree_store_append (tstore, &iter, &parent);
	gtk_tree_store_set (tstore, &iter,
						   3, "1255,11",
						   -1);
	gtk_tree_store_append (tstore, &iter, &parent);
	gtk_tree_store_set (tstore, &iter,
						   3, "2001,99",
						   -1);

	gtk_tree_store_append (tstore, &parent, NULL);
	gtk_tree_store_set (tstore, &parent,
						   0, 2,
						   1, "Jane",
						   2, "Do",
						   -1);
	gtk_tree_store_append (tstore, &iter, &parent);
	gtk_tree_store_set (tstore, &iter,
						   3, "9999,55",
						   -1);
	gtk_tree_store_append (tstore, &iter, &parent);
	gtk_tree_store_set (tstore, &iter,
						   3, "9999,11",
						   -1);
	gtk_tree_store_append (tstore, &iter, &parent);
	gtk_tree_store_set (tstore, &iter,
						   3, "9999,99",
						   -1);
	gtk_tree_store_append (tstore, &iter, &parent);
	gtk_tree_store_set (tstore, &iter,
						   3, "19999,11",
						   -1);

	gtk_widget_show_all (w);

	gtk_main ();

	return 0;
}
