/*
 * my_ctype.h
 *
 *  Created on: Jun 8, 2022
 *      Author: GM
 */

#ifndef MY_CTYPE_H_
#define MY_CTYPE_H_



#endif /* MY_CTYPE_H_ */



/// @brief Convierte una cadena 'A Formato Titulo'.
///
/// @param str -> cadena a convertir a formato título
///
/// @return Retorna 1 en caso de éxito, 0 en caso de falla.
int totitle(char *str);


/// @brief Recibe una cadena, recorta según una longitud máxima (agregando puntos suspensivos "...")
/// 	   y devuelve una versión recortada en la cadena "shorted" de destino.
///
/// @param shorted -> puntero para devolver la cadena recortada
/// @param size	   -> tamaño de la cadena de destino
/// @param string  -> cadena de origen
/// @param max	   -> longitud máxima aceptada
///
/// @return Retorna 1 en caso de éxito, 0 en caso de falla.
int shortenstr(char* shorted, int size, const char* string, int max);
