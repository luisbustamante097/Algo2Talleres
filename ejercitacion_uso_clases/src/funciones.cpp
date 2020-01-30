#include <vector>
#include <set>
#include <map>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    vector<int> res;
    set<int> set_res;
    for (int elem : s){
        set_res.insert(elem);
    }
    for (int elem : set_res) {
        res.push_back(elem);
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    vector<int> res;
    set<int> set_res;
    for (int elem : s){
        set_res.insert(elem);
    }
    for (int elem : set_res) {
        res.push_back(elem);
    }
    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> set_res_a;
    set<int> set_res_b;
    for (int elem_a : a){
        set_res_a.insert(elem_a);
    }
    for (int elem_b : b){
        set_res_b.insert(elem_b);
    }
    return set_res_a == set_res_b;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> set_res_a;
    set<int> set_res_b;
    for (int elem_a : a){
        set_res_a.insert(elem_a);
    }
    for (int elem_b : b){
        set_res_b.insert(elem_b);
    }
    return set_res_a == set_res_b;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int,int> res;
    for (int elem : s){
        res[elem]+=1;
    }
    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> res;
    map<int,int> res_map = contar_apariciones(s);
    for (int elem : s){
        if (res_map[elem]==1){
            res.push_back(elem);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for (int elem : b){
        if (a.count(elem)!=0){
            res.insert(elem);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res;
    for (int i = 0; i < 9; ++i) {
        set<int> set_i;
        for (int elem : s) {
            if (elem % 10 == i){
                set_i.insert(elem);
            }
        }
        if (!set_i.empty()){
            res[i]=set_i;
        }
    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res;
    map<char,char> dicc;
    if(tr.empty()){
        res = str;
    } else{
        for(pair <char,char> elem_tr : tr){
            dicc[elem_tr.first] = elem_tr.second;
        }
        for (char elem_str : str){
            if (dicc.count(elem_str)){
                res.push_back(dicc[elem_str]);
            } else{
                res.push_back(elem_str);
            }
        }
    }
    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    bool res = false;
    for (int i = 0; i < s.size() -1; ++i) {
        for (int j = i+1; j < s.size(); ++j) {
            if (s[i].libretas() != s[j].libretas()){
                for (LU lu : s[i].libretas()) {
                    if (s[j].libretas().count(lu)){
                        res = true;
                    }
                }
            }
        }
    }
    return res;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;
    map<set<LU>, vector<Mail>> diccMail;
    if (!s.empty()) {
        for (Mail mail : s) {
            diccMail[mail.libretas()].push_back(mail);
        }
        for (pair<set<LU>, vector<Mail>> elem : diccMail) {
            Mail ultimo = elem.second[0];
            for (Mail mail : elem.second) {
                if (ultimo.fecha() < mail.fecha() && mail.adjunto()) {
                    ultimo = mail;
                }
            }
            res[elem.first] = ultimo;
        }
    }
    return res;
}
