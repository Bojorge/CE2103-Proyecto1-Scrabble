#include <gtk/gtk.h>
#include <gtk/gtkmain.h>
#include <thread>
#include <functional>

using namespace std;
static gboolean movimiento_mouse(GtkWidget *widget, GdkEvent *event, gpointer user_data);

static gboolean my_keypress_function(GtkWidget *widget, GdkEventKey *event, gpointer user_data);

static gboolean btn_press_callback(GtkWidget *widget, GdkEventButton *event, gpointer user_data);

int mousex;
int mousey;
bool done = false;
bool agarrada=false;

GtkWidget *window;
GtkWidget *tablero, *pieza_a, *hbox, *fixed, *pieza_b, *pieza_c, *pieza_ch, *pieza_d, *pieza_e, *pieza_f, *pieza_g, *caja,
        *pieza_h, *pieza_i, *pieza_j, *pieza_k, *pieza_l, *pieza_ll, *pieza_m, *pieza_n, *pieza_nie, *pieza_o, *pieza_p, *pieza_q, *pieza_r
, *pieza_rr, *pieza_s, *pieza_t, *pieza_u, *pieza_v, *pieza_x, *pieza_y, *pieza_z;
GdkEvent click;

int main(int argc,char *argv[]) {

        gtk_init(NULL, NULL);

        //printf("asdf \n");

        gdouble mx, my;

        printf("cordenaas: (%u,%u)\n", mousex, mousey);

        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        fixed = gtk_fixed_new();
        caja = gtk_event_box_new();
        gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
        gtk_widget_add_events(window, GDK_KEY_PRESS_MASK);

        gtk_window_set_title(GTK_WINDOW(window), "tablero Scrable");
        tablero = gtk_image_new_from_file("tablero.jpg");

        gtk_container_add(GTK_CONTAINER(fixed), tablero);
        pieza_a = gtk_image_new_from_file("a.jpg");
        pieza_b = gtk_image_new_from_file("b.jpg");
        pieza_c = gtk_image_new_from_file("c.jpg");
        pieza_ch = gtk_image_new_from_file("ch.jpg");
        pieza_d = gtk_image_new_from_file("d.jpg");
        pieza_e = gtk_image_new_from_file("e.jpg");
        pieza_f = gtk_image_new_from_file("f.jpg");
        pieza_g = gtk_image_new_from_file("g.jpg");
        pieza_h = gtk_image_new_from_file("h.jpg");
        pieza_i = gtk_image_new_from_file("i.jpg");
        pieza_j = gtk_image_new_from_file("j.jpg");
        pieza_l = gtk_image_new_from_file("l.jpg");
        pieza_ll = gtk_image_new_from_file("ll.jpg");
        pieza_m = gtk_image_new_from_file("m.jpg");
        pieza_n = gtk_image_new_from_file("n.jpg");
        pieza_nie = gtk_image_new_from_file("nie.jpg");
        pieza_o = gtk_image_new_from_file("o.jpg");
        pieza_p = gtk_image_new_from_file("p.jpg");
        pieza_q = gtk_image_new_from_file("q.jpg");
        pieza_r = gtk_image_new_from_file("r.jpg");
        pieza_rr = gtk_image_new_from_file("rr.jpg");
        pieza_s = gtk_image_new_from_file("s.jpg");
        pieza_t = gtk_image_new_from_file("t.jpg");
        pieza_u = gtk_image_new_from_file("u.jpg");
        pieza_v = gtk_image_new_from_file("v.jpg");
        pieza_x = gtk_image_new_from_file("x.jpg");
        pieza_y = gtk_image_new_from_file("y.jpg");
        pieza_z = gtk_image_new_from_file("z.jpg");




        //gtk_container_add(GTK_CONTAINER(fixed),pieza_a);


        //gtk_fixed_put(GTK_CONTAINER(caja),pieza_a,0,0);


        gtk_container_add(GTK_CONTAINER(window), fixed);
        g_signal_connect(G_OBJECT(window), "destroy",
                         G_CALLBACK(gtk_main_quit), NULL);
        g_signal_connect(G_OBJECT(window), "motion-notify-event", G_CALLBACK(movimiento_mouse), NULL);
        gtk_widget_set_events(window, GDK_POINTER_MOTION_MASK);
        g_signal_connect (G_OBJECT(window), "key_press_event", G_CALLBACK(my_keypress_function), NULL);
        g_signal_connect(G_OBJECT(window), "button-press-event", G_CALLBACK(btn_press_callback), NULL);
        gtk_fixed_put(GTK_FIXED(fixed), pieza_a, 5, 3);
            string e="e.jpg";
            gchar letra[10];
            strcpy(letra,e.c_str());
            gtk_fixed_put(GTK_FIXED(fixed), pieza_b, 73, 73);
            gtk_fixed_put(GTK_FIXED(fixed), pieza_d, 108, 108);
            gtk_fixed_put(GTK_FIXED(fixed), gtk_image_new_from_file("e.jpg"), 142, 143);
            gtk_fixed_put(GTK_FIXED(fixed), pieza_f, 175, 178);
            gtk_fixed_put(GTK_FIXED(fixed), pieza_g, 120, 537);
            gtk_fixed_put(GTK_FIXED(fixed), pieza_h, 160, 537);
            gtk_fixed_put(GTK_FIXED(fixed), pieza_i, 200, 537);
            gtk_fixed_put(GTK_FIXED(fixed), pieza_j, 240, 537);
            gtk_fixed_put(GTK_FIXED(fixed), pieza_l, 280, 537);
            gtk_fixed_put(GTK_FIXED(fixed), pieza_ll, 320, 537);
            gtk_fixed_put(GTK_FIXED(fixed), pieza_m, 360, 537);
            gtk_fixed_put(GTK_FIXED(fixed), gtk_image_new_from_file(letra), (7*34+5), 7*35+3);




    gtk_widget_show_all(window);

            gtk_main();
            return 0;

    //return 0;
}


static gboolean movimiento_mouse(GtkWidget *widget, GdkEvent *event, gpointer user_data) {

    if (event->type == GDK_MOTION_NOTIFY) {
        GdkEventMotion *e = (GdkEventMotion *) event;

        mousex = (guint) e->x;
        mousey = (guint) e->y;
        gtk_fixed_move(GTK_FIXED(fixed), pieza_b, mousex, mousey);




        gtk_widget_show_all(window);

    }
}

gboolean my_keypress_function(GtkWidget *widget, GdkEventKey *event, gpointer data) {
    printf("letra presionada!");
    if (event->keyval == GDK_KEY_a) {
        printf("letra presionada!");
    }
}

gboolean btn_press_callback(GtkWidget *btn, GdkEventButton *event, gpointer userdata) {
    if (event->type == GDK_BUTTON_PRESS && event->button == 1) {//1 is left mouse btn
        printf("Coordinates: (%u,%u)\n", mousex, mousey);
        if(mousex>6 && mousex<511) {
            int posx = (mousex - 5) / 34;
            int posy= (mousey- 3)/35;
            printf("posicion en la matriz (%u,%u) \n", posx,posy);
            //gtk_main();
        }
        else{
            printf("no esta en la matriz");
        }


    }

}








