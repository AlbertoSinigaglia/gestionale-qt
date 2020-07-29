
namespace UFMath{

/**     PROPORZIONALE A MEDIA
 * La funzione templetizzata ritorna il valore calcolato proporzionalemente sulla base 
 * di un valore medio che corrisponde alla percentuale media ( 0.5 )
 */
//assunzione 1 : T implementa operatore < * > e conversione double -> T
template <class T>
T proporzionaleAMedia(T media, double percentuale){
    return T * static_cast<T>(0.5 / percentuale);
}

/**     PROPORZIONALE A MEDIA
 * La funzione templetizzata ritorna il valore calcolato proporzionalemente sulla base 
 * di un valore medio che corrisponde al grado medio ( 5 )
 */
//assunzione 1 : T implementa operatore < * > e conversione double -> T
template <class T>
T proporzionaleAMedia(T media, unsigned int grado){
    return T * static_cast<T>(5 / grado);
}

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