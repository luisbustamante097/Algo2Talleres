#include "gtest-1.8.1/gtest.h"
#include "../src/Diccionario.h"

#if EJ >= 4
TEST(diccionario, ej4_def) {
	Diccionario d;
	ASSERT_FALSE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(1, 10);
	ASSERT_TRUE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(2, 20);
	ASSERT_TRUE(d.def(1));
	ASSERT_TRUE(d.def(2));
	ASSERT_FALSE(d.def(3));
}

TEST(diccionario, ej4_obtener) {
	Diccionario d;
	d.definir(1, 4);
	ASSERT_EQ(d.obtener(1), 4);
	d.definir(1, 44);
	ASSERT_EQ(d.obtener(1), 44);
	d.definir(2, 5);
	ASSERT_EQ(d.obtener(1), 44);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(1, 444);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(2, 55);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 55);
}
#endif

#if EJ >= 5

TEST(diccionario_borrar, ej5_borrar_correctamente) {
    Diccionario d;
    d.definir(1, 4);
    d.definir(2, 5);
    d.borrar(1);
    ASSERT_FALSE(d.def(1));
    d.borrar(2);
    ASSERT_FALSE(d.def(2));
}

TEST(diccionario_borrar, ej5_borrar_y_verificar) {
    Diccionario d;
    d.definir(1, 4);
    d.definir(2, 5);
    d.definir(3, 6);
    d.borrar(1);
    ASSERT_FALSE(d.def(1));
    ASSERT_EQ(d.obtener(2), 5);
    ASSERT_EQ(d.obtener(3), 6);
}

TEST(diccionario_borrar, ej5_borrar_inexistente) {
    Diccionario d;
    d.definir(1, 4);
    d.definir(2, 5);
    d.definir(3, 6);
    d.borrar(4);
    ASSERT_EQ(d.obtener(1), 4);
    ASSERT_EQ(d.obtener(2), 5);
    ASSERT_EQ(d.obtener(3), 6);
}

#endif


#if EJ >= 6

int apariciones (vector<Clave> v, Clave x){
    int res = 0;
    for (Clave c : v){
        if (c == x){
            res++;
        }
    }
    return res;
}

bool esPermutacion(vector<Clave> v1, vector<Clave> v2){
    bool res = true;
    for (Clave c : v1){
        if (apariciones(v1,c) != apariciones(v2,c)){
            res = false;
        }
    }
    for (Clave c : v2){
        if (apariciones(v2,c) != apariciones(v1,c)){
            res = false;
        }
    }
    return res;
}

TEST(diccionario_vector_claves, ej6_claves) {
    Diccionario d;
    vector<Clave> v_clave = {1,2,3};
    d.definir(1, 4);
    d.definir(2, 5);
    d.definir(3, 6);
    ASSERT_TRUE(esPermutacion(d.claves(), v_clave));
}

TEST(diccionario_vector_claves, ej6_sin_claves) {
    Diccionario d;
    vector<Clave> v_clave;
    ASSERT_TRUE(esPermutacion(d.claves(), v_clave));
}

TEST(diccionario_vector_claves, ej6_una_faltante) {
    Diccionario d;
    vector<Clave> v_clave = {1,2,3};
    d.definir(1, 4);
    d.definir(2, 5);
    ASSERT_FALSE(esPermutacion(d.claves(), v_clave));
}
TEST(diccionario_vector_claves, ej6_sin_repetidos) {
    Diccionario d;
    vector<Clave> v_clave = {1};
    d.definir(1, 4);
    d.definir(1, 3);
    d.definir(1, 6);
    ASSERT_TRUE(esPermutacion(d.claves(), v_clave));
}

// Completar para el ejercicio 6

#endif

#if EJ >= 7
TEST(diccionario_iguales, ej7_iguales) {
    Diccionario d1;
    d1.definir(1, 1);
    d1.definir(2, 2);
    d1.definir(3, 3);
    Diccionario d2;
    d2.definir(3, 3);
    d2.definir(2, 2);
    d2.definir(1, 1);
    ASSERT_TRUE(d1 == d2);
}

TEST(diccionario_iguales, ej7_falta_uno) {
    Diccionario d1;
    d1.definir(1, 1);
    d1.definir(2, 2);
    Diccionario d2;
    d2.definir(3, 3);
    d2.definir(2, 2);
    d2.definir(1, 1);
    ASSERT_FALSE(d1 == d2);
}

TEST(diccionario_iguales, ej7_distintos) {
    Diccionario d1;
    d1.definir(1, 1);
    d1.definir(2, 2);
    d1.definir(3, 3);
    Diccionario d2;
    d2.definir(3, 2);
    d2.definir(2, 2);
    d2.definir(1, 1);
    ASSERT_FALSE(d1 == d2);
}
TEST(diccionario_iguales, ej7_vacios) {
    Diccionario d1;
    Diccionario d2;
    ASSERT_TRUE(d1 == d2);
}

TEST(diccionario_iguales, ej7_uno_vacio) {
    Diccionario d1;
    d1.definir(1, 1);
    Diccionario d2;
    ASSERT_FALSE(d1 == d2);
}

// Completar para el ejercicio 7

#endif

#if EJ >= 8

TEST(diccionario_union, ej8_iguales) {
    Diccionario d1;
    d1.definir(1, 1);
    d1.definir(2, 2);
    d1.definir(3, 3);
    Diccionario d2;
    d2.definir(3, 3);
    d2.definir(2, 2);
    d2.definir(1, 1);
    Diccionario r;
    r.definir(3, 3);
    r.definir(2, 2);
    r.definir(1, 1);
    ASSERT_TRUE((d1 || d2) == r);
}

TEST(diccionario_union, ej8_union1) {
    Diccionario d1;
    d1.definir(1, 1);
    Diccionario d2;
    d2.definir(3, 3);
    d2.definir(2, 2);
    Diccionario r;
    r.definir(3, 3);
    r.definir(2, 2);
    r.definir(1, 1);
    ASSERT_TRUE((d1 || d2) == r);
}

TEST(diccionario_union, ej8_d1_vacio) {
    Diccionario d1;
    d1.definir(1, 1);
    Diccionario d2;
    Diccionario r;
    r.definir(1, 1);
    ASSERT_TRUE((d1 || d2) == r);
}

TEST(diccionario_union, ej8_d2_vacio) {
    Diccionario d1;
    Diccionario d2;
    d2.definir(2, 2);
    d2.definir(1, 1);
    Diccionario r;
    r.definir(2, 2);
    r.definir(1, 1);
    ASSERT_TRUE((d1 || d2) == r);
}


TEST(diccionario_union, ej8_vacios) {
    Diccionario d1;
    Diccionario d2;
    Diccionario r;
    ASSERT_TRUE((d1 || d2) == r);
}

TEST(diccionario_vacio, ej8_solo_uno_en_ambos) {
    Diccionario d1;
    d1.definir(1, 1);
    Diccionario d2;
    d2.definir(1, 1);
    Diccionario r;
    r.definir(1, 1);
    ASSERT_TRUE((d1 || d2) == r);
}

TEST(diccionario_union, ej8_union2) {
    Diccionario d1;
    d1.definir(1, 1);
    d1.definir(2, 2);
    d1.definir(3, 3);
    Diccionario d2;
    d2.definir(3, 3);
    d2.definir(2, 2);
    d2.definir(1, 1);
    Diccionario r;
    ASSERT_FALSE((d1 || d2) == r);
}

TEST(diccionario_union, ej8_union3) {
    Diccionario d1;
    d1.definir(2, 2);
    Diccionario d2;
    d2.definir(3, 3);
    Diccionario r;
    r.definir(3, 3);
    r.definir(2, 2);
    ASSERT_TRUE((d1 || d2) == r);
}

TEST(diccionario_union, ej8_val_distinto1) {
    Diccionario d1;
    d1.definir(1, 10);
    Diccionario d2;
    d2.definir(1, 1);
    Diccionario r;
    r.definir(1, 10);
    ASSERT_TRUE((d1 || d2) == r);
}

TEST(diccionario_union, ej8_val_distinto2) {
    Diccionario d1;
    d1.definir(1, 1);
    d1.definir(2, 2);
    d1.definir(3, 33);
    Diccionario d2;
    d2.definir(3, 3);
    d2.definir(2, 2);
    d2.definir(1, 1);
    Diccionario r;
    r.definir(3, 3);
    r.definir(2, 2);
    r.definir(1, 1);
    ASSERT_FALSE((d1 || d2) == r);
}

TEST(diccionario_union, ej8_val_distinto3) {
    Diccionario d1;
    d1.definir(1, 10);
    d1.definir(2, 2);
    d1.definir(3, 33);
    Diccionario d2;
    d2.definir(3, 3);
    d2.definir(2, 22);
    d2.definir(1, 1);
    Diccionario r;
    r.definir(3, 33);
    r.definir(2, 2);
    r.definir(1, 10);
    ASSERT_TRUE((d1 || d2) == r);
}

TEST(diccionario_union, ej8_val_distinto4) {
    Diccionario d1;
    d1.definir(1, 1);
    d1.definir(2, 2);
    d1.definir(3, 3);
    Diccionario d2;
    d2.definir(3, 33);
    d2.definir(2, 22);
    d2.definir(1, 11);
    Diccionario r;
    r.definir(3, 33);
    r.definir(2, 22);
    r.definir(1, 11);
    ASSERT_FALSE((d1 || d2) == r);
}

/////////////////////////////////////

TEST(diccionario_interseccion, ej8_iguales) {
    Diccionario d1;
    d1.definir(1, 1);
    d1.definir(2, 2);
    d1.definir(3, 3);
    Diccionario d2;
    d2.definir(3, 3);
    d2.definir(2, 2);
    d2.definir(1, 1);
    Diccionario r;
    r.definir(3, 3);
    r.definir(2, 2);
    r.definir(1, 1);
    ASSERT_TRUE((d1 && d2) == r);
}

TEST(diccionario_interseccion, ej8_interseccion_solo_uno) {
    Diccionario d1;
    d1.definir(1, 1);
    d1.definir(4, 4);
    d1.definir(5, 5);
    Diccionario d2;
    d2.definir(3, 3);
    d2.definir(2, 2);
    d2.definir(1, 1);
    Diccionario r;
    r.definir(1, 1);
    ASSERT_TRUE((d1 && d2) == r);
}

TEST(diccionario_interseccion, ej8_valor_en_clave_distinto) {
    Diccionario d1;
    d1.definir(1, 10);
    d1.definir(2, 2);
    Diccionario d2;
    d2.definir(2, 2);
    d2.definir(1, 1);
    Diccionario r;
    r.definir(1, 10);
    r.definir(2, 2);
    ASSERT_TRUE((d1 && d2) == r);
}

TEST(diccionario_interseccion, ej8_solo_uno_en_ambos) {
    Diccionario d1;
    d1.definir(1, 1);
    Diccionario d2;
    d2.definir(1, 1);
    Diccionario r;
    r.definir(1, 1);
    ASSERT_TRUE((d1 && d2) == r);
}

TEST(diccionario_interseccion, ej8_vacios) {
    Diccionario d1;
    Diccionario d2;
    Diccionario r;
    ASSERT_TRUE((d1 && d2) == r);
}

TEST(diccionario_interseccion, ej8_uno_vacio) {
    Diccionario d1;
    d1.definir(1, 1);
    d1.definir(2, 2);
    d1.definir(3, 3);
    Diccionario d2;
    Diccionario r;
    r.definir(3, 3);
    r.definir(2, 2);
    r.definir(1, 1);
    ASSERT_FALSE((d1 && d2) == r);
}

TEST(diccionario_interseccion, ej8_inter1) {
    Diccionario d1;
    d1.definir(1, 1);
    d1.definir(2, 2);
    d1.definir(3, 3);
    Diccionario d2;
    d2.definir(2, 2);
    d2.definir(1, 1);
    Diccionario r;
    r.definir(2, 2);
    r.definir(1, 1);
    ASSERT_TRUE((d1 && d2) == r);
}

TEST(diccionario_interseccion, ej8_inter2) {
    Diccionario d1;
    d1.definir(1, 1);
    Diccionario d2;
    d2.definir(1, 10);
    Diccionario r;
    r.definir(1, 1);
    ASSERT_TRUE((d1 && d2) == r);
}

TEST(diccionario_interseccion, ej8_val_distinto1) {
    Diccionario d1;
    d1.definir(1, 1);
    d1.definir(2, 2);
    d1.definir(3, 3);
    Diccionario d2;
    d2.definir(3, 3);
    d2.definir(2, 2);
    d2.definir(1, 10);
    Diccionario r;
    r.definir(3, 3);
    r.definir(2, 2);
    r.definir(1, 1);
    ASSERT_TRUE((d1 && d2) == r);
}

TEST(diccionario_interseccion, ej8_val_distinto2) {
    Diccionario d1;
    d1.definir(1, 1);
    Diccionario d2;
    d2.definir(3, 3);
    d2.definir(2, 2);
    d2.definir(1, 11);
    Diccionario r;
    r.definir(1, 1);
    ASSERT_TRUE((d1 && d2) == r);
}

TEST(diccionario_interseccion, ej8_val_distinto3) {
    Diccionario d1;
    d1.definir(1, 11);
    Diccionario d2;
    d2.definir(1, 1);
    Diccionario r;
    r.definir(1, 11);
    ASSERT_TRUE((d1 && d2) == r);
}

#endif

