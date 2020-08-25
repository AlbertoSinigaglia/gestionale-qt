namespace UFMath{

    /**     MEDIA PONDERATA
     * La funzione ritorna la media ponderata di due valori con i rispettivi pesi
     */
    // assunzione 1 : V deve essere convertibile in T
    // assunzione 2 : T implementa operatori < * > , < / > e < + >
    template <class T, class V>
    T mediaPonderata(V peso1, T valore1, V peso2, T valore2){
        return (valore1*peso1 + valore2*peso2) / static_cast<T>(peso1+peso2);
    }
}
