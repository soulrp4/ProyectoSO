int contador;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Aquí iria todo el groso del codigo de nuestro servidor, procesando cada codigo...

if ((codigo == 1)||(codigo == 2)||(codigo == 3))
{
	pthread_mutex_lock( &mutex );
	contador = contador + 1;
	pthread_mutex_unlock( &mutex );
}
else if (codigo == 4)
	sprintf (respuesta,"%d",contador);