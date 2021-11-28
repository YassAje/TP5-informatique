 #include <stdio.h>
 #include <stdlib.h>
 #include "messages.h"
                    /*.....................Déclaration de la structure.................*/
typedef struct{
	unsigned char premier_char;
	unsigned char second_char;
	int taille;
	int reserve;
	int position_RVB;
} BMP_FILE_HEADER; 

int main(int argc,char *argv[]){

	int result;
	FILE *fp ;
	long taille_fichier;
	unsigned char *buf;
        printf(MSG_INFO_USAGE,argv[1]);
	BMP_FILE_HEADER entete;
	
	printf("taille de structure : %ld\n",sizeof(BMP_FILE_HEADER));

	/*on a eu 16o au lieu de 14o parcequ'il c'est plus simple pour le programme d'avoir 4*4=16*/

	fp = fopen(argv[1],"rb");
        if(fp==NULL){
		printf(MSG_ERR_OPEN,argv[1]);
		perror("Erreur c'est ");
		return(-1);
	}
	
	
	/*.......................taille de fichier d'entrée...................................*/

  	fseek (fp , 0 , SEEK_END);

  	taille_fichier = ftell (fp);

  	rewind (fp);
			/*..................Position...................*/	

	buf = (char *) malloc ((taille_fichier)*sizeof(char));;

		/*....................Création de mémoire de sauvgarde..................*/

	if (buf == NULL) {

		printf ("Memory error",stderr); 

		return(-1);
	}
	
	result = fread (buf,1,taille_fichier,fp);

		/*........................Placement dans la mémoire...........................*/

	if (result != taille_fichier) {

		printf ("Reading error",stderr); 

		return(-1);
	}
	
		entete.premier_char=buf[0];	

		entete.second_char=buf[1];

		entete.taille=(buf[5]<<24)+(buf[4]<<16)+(buf[3]<<8)+buf[2];

		entete.reserve=(buf[9]<<24)+(buf[8]<<16)+(buf[7]<<8)+buf[6];

		entete.position_RVB=(buf[13]<<24)+(buf[12]<<16)+(buf[11]<<8)+buf[10];	
	
	
	printf ("Verification BMP : %c%c\n",entete.premier_char,entete.second_char);

	if(entete.premier_char=='B' && entete.second_char =='M'){
		
             /*..............................Affichage......................................*/

		printf("C'est bien un fichier BMP\n");

		printf ("Premier mot 4 octets/32bits (taille du fichier) en HEX : %08X\n",entete.taille);
                
                printf ("Taille en décimal: %d\n",entete.taille);

		printf ("Second mot 4 octets/32bits (les deux reserved) en HEX : %08X\n",entete.reserve);

		printf ("Troisieme mot 4 octets/32bits (offset to pixelarray) en HEX : %08X\n",entete.position_RVB);
                
                printf ("Offset en décimal : %d\n",entete.position_RVB);

	}else{

		printf("C'est pas un fichier BMP\n");	
	}

	fclose(fp);

	free(buf);
	
return (EXIT_SUCCESS);

}
/*
on trouve une taille de 0x000F54FA ce qui donne 1004794 en décimal, ce qui est bien la taille de notre fichier BMP
*/
