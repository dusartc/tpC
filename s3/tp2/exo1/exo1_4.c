void ajoute_apres(int dest[], int tailleDest, int src[], int tailleSrc){
	for(int i=0;i<tailleSrc;i++){
		dest[i+(tailleDest-tailleSrc)] = src[i];
	}
}
