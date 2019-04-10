#include <gtk/gtk.h>
#include <gtk/gtkmain.h>
#include <thread>
#include <functional>
#include "Lista.h"
#include "Nodo.h"
#include "ListaLetras.h"
#include "utiles.h"
#include "TCPclient.h"



using namespace std;
static gboolean movimiento_mouse(GtkWidget *widget, GdkEvent *event, gpointer user_data);

static gboolean my_keypress_function(GtkWidget *widget, GdkEventKey *event, gpointer user_data);

static gboolean btn_press_callback(GtkWidget *widget, GdkEventButton *event, gpointer user_data);

int mousex;
int mousey;
int manox;
bool done = false;
bool agarrada=false;
bool socket_iniciado=false;
int pieza_agarrada;
bool enviado=false;
bool recibido=false;

GtkWidget *window;
GtkWidget *tablero, *hbox, *lienzo, *caja, *boton1,*boton2;
GdkEvent click;

Lista *palabras_tablero=new Lista();
Lista *palabras_preliminares=new Lista();
Lista *palabras_mano=new Lista();
ListaLetras *traductor=new ListaLetras();
utiles *funcion=new utiles();

TCPclient *cliente=new TCPclient();
string mensaje;
int sockfd;
void *coneccion(void*){
    cliente->iniciar();
}
void *mensajes(void*){
    while(true) {
        mensaje = cliente->pruebabuff();
        sockfd=cliente->get_sockfd();

    }
}
void *grafica(void*){
    gtk_main();
};
int main(int argc,char *argv[]) {

    gtk_init(NULL, NULL);

    printf("asdf \n");

    gdouble mx, my;

    printf("cordenaas: (%u,%u)\n", mousex, mousey);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    lienzo = gtk_fixed_new();
    caja = gtk_event_box_new();
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    gtk_widget_add_events(window, GDK_KEY_PRESS_MASK);

    gtk_window_set_title(GTK_WINDOW(window), "Tablero Scrable");

    tablero = gtk_image_new_from_file("tablero.jpg");

    gtk_container_add(GTK_CONTAINER(lienzo), tablero);



    //gtk_container_add(GTK_CONTAINER(fixed),pieza_a);


    //gtk_fixed_put(GTK_CONTAINER(caja),pieza_a,0,0);


    gtk_container_add(GTK_CONTAINER(window), lienzo);
    g_signal_connect(G_OBJECT(window), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);

    g_signal_connect(G_OBJECT(window), "motion-notify-event", G_CALLBACK(movimiento_mouse), NULL);
    gtk_widget_set_events(window, GDK_POINTER_MOTION_MASK);
    g_signal_connect (G_OBJECT(window), "key_press_event", G_CALLBACK(my_keypress_function), NULL);
    g_signal_connect(G_OBJECT(window), "button-press-event", G_CALLBACK(btn_press_callback), NULL);
    //gtk_fixed_put(GTK_FIXED(lienzo), pieza_a, 5, 3);
    string e = "e.jpg";
    gchar letras[10];
    strcpy(letras, e.c_str());

    gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("z.jpg"), (7 * 34 + 5), 7 * 35 + 3);
    //for (int i=0;i<=palabras_tablero->tamano();i+3){
    printf("la posicion 4 de la lista tiene %u \n", palabras_tablero->obtener_dato(4));

    gtk_widget_show_all(window);



    pthread_t t3;
    pthread_create(&t3,NULL,&grafica,NULL);


    void*result;
    pthread_t t1;
    pthread_create(&t1,NULL,&coneccion,NULL);
    printf("\n iniciando coneccion");
    pthread_t t2;
    pthread_create(&t2,NULL,&mensajes,NULL);
    printf("\nsocket iniciadoo\n");
    pthread_join(t2, &result);
    pthread_join(t1,&result);
    pthread_join(t3,&result);


    return 0;
}


static gboolean movimiento_mouse(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    std::cout<<"\n ultimo mensaje "<<mensaje<<std ::endl;
    string plt="0";
    if (enviado==true){
        Lista *entrada=funcion->castear_Lista_to_String(mensaje);
        for(int i=1;i<=entrada->tamano()-1;i++){
            //printf("agregando a las listas");
            if(entrada->obtener_dato(0)==0){
                //printf("agregando a la mano");
                palabras_mano->anadir_final(entrada->obtener_dato(i));
                enviado=false;
            }
            if(entrada->obtener_dato(0)==1){
                palabras_tablero->anadir_final(entrada->obtener_dato(i));
                enviado=false;
            }


        }



    }
    if (event->type == GDK_MOTION_NOTIFY) {
        GdkEventMotion *e = (GdkEventMotion *) event;
        mousex = (guint) e->x;
        mousey = (guint) e->y;

        gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("tablero.jpg"),0,0);

        //SE PONEN LAS LETRAS DE LAS PALABRAS PRELIMINARES
        if (agarrada==true){
            int codigo = pieza_agarrada;
            string trad_codigo = traductor->traducir(codigo);
            trad_codigo = trad_codigo + ".jpg";
            gchar letra[10];
            strcpy(letra, trad_codigo.c_str());
            gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file(letra), mousex - 14, mousey - 15);
        }
        for (int i=0;i<=palabras_tablero->tamano()-1;i++){
            int codigo =palabras_tablero->obtener_dato(i+2);
            string trad_codigo=traductor->traducir(codigo);
            trad_codigo=trad_codigo+".jpg";
            gchar letra[10];
            strcpy(letra,trad_codigo.c_str());
            gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file(letra), ((palabras_tablero->obtener_dato(i+1))*34+5),((palabras_tablero->obtener_dato(i)))*35+3);
            gtk_widget_show_all(window);

            //printf("dato: %u \n",palabras_tablero->obtener_dato(i));
            i++;
            i++;
        }
        if (palabras_preliminares->tamano()>=3) {
            for (int i = 0; i <= palabras_preliminares->tamano() - 1; i++) {
                int codigo = palabras_preliminares->obtener_dato(i + 2);
                string trad_codigo = traductor->traducir(codigo);
                trad_codigo = trad_codigo + ".jpg";
                gchar letra[10];
                strcpy(letra, trad_codigo.c_str());
                //gtk_fixed_put(GTK_FIXED(lienzo), pieza_m, mousex-15, mousey-14);

                gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file(letra),
                              ((palabras_preliminares->obtener_dato(i+1)) * 34 + 5),
                              ((palabras_preliminares->obtener_dato(i))) * 35 + 3);

                gtk_widget_show_all(window);

                i++;
                i++;
            }
        }
        if (palabras_mano->tamano()>=0) {
            for (int i = 0; i <= palabras_mano->tamano() - 1; i++) {
                int codigo = palabras_mano->obtener_dato(i);
                string trad_codigo = traductor->traducir(codigo);
                trad_codigo = trad_codigo + ".jpg";
                gchar letra[10];
                strcpy(letra, trad_codigo.c_str());
                gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file(letra),120+40*i,537);
                gtk_widget_show_all(window);

                //printf("dato: %u \n", palabras_preliminares->obtener_dato(i));

            }
        }


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
        //printf("Coordinates: (%u,%u)\n", mousex, mousey);
        //PONE LA PIEZA EN LA CASILLA INDICADA
        //MANEJO DE BOTONES EN LA MATRIZ------------------------------
        if(mousex>6 && mousex<511 && mousey<527) {
            int posx = (mousex - 5) / 34;
            int posy = (mousey - 3) / 35;
            if(funcion->encadenado(palabras_tablero,palabras_preliminares,posy,posx)==true) {
                palabras_preliminares->anadir_final(posy);
                palabras_preliminares->anadir_final(posx);
                palabras_preliminares->anadir_final(pieza_agarrada);
                pieza_agarrada = NULL;
                agarrada = false;
                //printf("agregando a la pos %u,%u", posx, posy);
            }

                //printf("posicion en la matriz (%u,%u) \n", posx,posy);

        }
        //BOTON QUE INICIA LA CONECCION CON LOS SOCKETS
        if (mousey>64 && mousey<530 && mousex>530 && mousex<650 ){
            string paquete="iniciar";
            cliente->enviarPaquete(sockfd, paquete);
            enviado=true;
            recibido=true;
            //socket_iniciado=true;
            printf("iniciando sockets");
        }
        //MANEJO DE LA MATRIZ GRAFICA
        if(mousey>537 && mousey<572 && mousex>120 && mousex<395){
            manox=(mousex-120)/40;
            agarrada=true;
            pieza_agarrada=palabras_mano->obtener_dato(manox);
            palabras_mano->borrar_Dato(manox+1);
            //printf("pos mano x %u",manox);

        }
        //BOTON QUE ENVIA LAS LETAS COLOCALADAS-----------------------------------------------
        if(mousex>530 && mousex<780 && mousey>370 && mousey<440 ){
            if (recibido==false) {
                std::cout << "\n enviando " << funcion->castear(palabras_preliminares) << std::endl;
                string paquete;
                paquete = funcion->castear(palabras_preliminares);
                char pacquetec[80];
                strcpy(pacquetec, paquete.c_str());
                cliente->enviarPaquete(sockfd, paquete);
                mensaje=cliente->pruebabuff();
                std::cout<<mensaje<<endl;
                recibido=true;
                enviado=true;


                //cliente->leerPaquete(sockfd);
                //mensaje=cliente->pruebabuff();
                //std::cout<<"el servidor envia"<<mensaje<<endl;

            }
        }
        //if (enviado==true){
            //mensaje=cliente->pruebabuff();
           // std::cout<<"el servidor envia"<<mensaje<<endl;

        //}
    }

}