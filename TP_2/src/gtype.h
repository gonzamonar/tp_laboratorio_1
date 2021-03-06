/*
 * gtype.h
 *
 *  Created on: May 14, 2022
 *      Author: GM
 */

#ifndef GTYPE_H_
#define GTYPE_H_
#endif /* GTYPE_H_ */


/// @brief Convierte una cadena 'A Formato Titulo'.
///
/// @param str -> cadena a convertir a formato t?tulo
///
/// @return Retorna 1 en caso de ?xito, 0 en caso de falla.
int totitle(char *str);


/// @brief Recibe una cadena, recorta seg?n una longitud m?xima (agregando puntos suspensivos "...")
/// 	   y devuelve una versi?n recortada en la cadena "shorted" de destino.
///
/// @param shorted -> puntero para devolver la cadena recortada
/// @param size	   -> tama?o de la cadena de destino
/// @param string  -> cadena de origen
/// @param max	   -> longitud m?xima aceptada
///
/// @return Retorna 1 en caso de ?xito, 0 en caso de falla.
int shortenstr(char* shorted, int size, const char* string, int max);
