 #include <stdio.h>
 #include <stdlib.h>
 #include "messages.h"
struct entete_struct {  /*structure (globale) ou seront stockées les infos de l'entete*/
	char signature[2];
	int taille;
	int offset;
	int taille_entete;
	int largeur;
	int longueur;
	int plans;
	int bpp;
	int compression;
	int taille_image;
	int Hresolution;
	int Vresolution;
	int nbr_couleur;
	int nbr_couleur_importante;
}BMP_FILE_HEADER;

int hex2dec (unsigned char hex[4],int nombre) /*Fonction permettant de convertir un nombre hexa
					      en décimal (plus facile à lire)*/
{
	int resultat = 0;
	int i;

	for (i = nombre - 1; i >= 0; i--)
	{
		resultat = resultat * 256 + hex[i];
	}
	return resultat;
}

void lire_fichier (char nom[255])
{
	unsigned char temp[4]; /*Zone mémoire temporaire où on stoque ce qui est lu dans le fichier avant
	       de le traiter.*/
          FILE * fichier; 
	fichier = fopen (nom,"r");

	fread (&BMP_FILE_HEADER.signature,2,1,fichier); /*signature codée sur 2 octets*/
	fread (&temp,4,1,fichier);
	BMP_FILE_HEADER.taille = hex2dec (temp,4); /*taille totale du fichier, 4 octets*/
	fread (&temp,4,1,fichier); /*reservé*/
	fread (&temp,4,1,fichier); /*Offset de début de l'image, 4 octets*/
	BMP_FILE_HEADER.offset = hex2dec (temp,4);
	fread (&temp,4,1,fichier); /*Taille de l'entete, 4 octets*/
	BMP_FILE_HEADER.taille_entete = hex2dec (temp,4);
	fread (&temp,4,1,fichier); /*Largeur, 4 octets*/
	BMP_FILE_HEADER.largeur = hex2dec(temp,4);
	fread (&temp,4,1,fichier); /*Longueur, 4 octets*/
	BMP_FILE_HEADER.longueur = hex2dec(temp,4);
	fread (&temp,2,1,fichier); /*Nombre de plans ( 1 ), 2 octets*/
	BMP_FILE_HEADER.plans = hex2dec (temp,2);
	fread (&temp,2,1,fichier); /*Nbre de bit par pixels, 2 octets*/
	BMP_FILE_HEADER.bpp = hex2dec (temp,2);
	fread (&temp,4,1,fichier); /*Compression, 0 = rien, 4 octets*/
	BMP_FILE_HEADER.compression = hex2dec (temp,4);
	fread (&temp,4,1,fichier); /*Taille de l'image, 4 octets*/
	BMP_FILE_HEADER.taille_image = hex2dec (temp,4);
	fread (&temp,4,1,fichier); /*Resolution horizotale en pixels par mètre, 4octets*/
	BMP_FILE_HEADER.Hresolution = hex2dec (temp,4);
	fread (&temp,4,1,fichier); /*Resolution verticale, en ixels par mètre, 4 octets*/
	BMP_FILE_HEADER.Vresolution = hex2dec (temp,4);
	fread (&temp,4,1,fichier); /*Nombre de couleur utilisées, 0 = toutes, 4 octets*/
	BMP_FILE_HEADER.nbr_couleur = hex2dec (temp,4);
	fread (&temp,4,1,fichier); 
	BMP_FILE_HEADER.nbr_couleur_importante = hex2dec (temp,4);

	/*Si c'est un image 8 bit, cette entête est suivie de la palette.
        Après la palette, ce sont les données de l'image*/
	
	fclose (fichier);
}

              int main(int argc,char *argv[]){	
	
	/*................................Affichages................................*/


	lire_fichier (argv[1]); /*le fichier qu'on va lire*/

	printf ("Signature : %s\n",BMP_FILE_HEADER.signature);

	printf ("Taille du fichier : %d\n",BMP_FILE_HEADER.taille);

	printf ("les valeurs RVB des pixels : %d\n",BMP_FILE_HEADER.offset);

	printf ("Taille de l'entete : %d\n",BMP_FILE_HEADER.taille_entete);

	printf ("Largeur en pixels: %d\n",BMP_FILE_HEADER.largeur);

	printf ("Longueur en pixels : %d\n",BMP_FILE_HEADER.longueur);

	printf ("Nombre de plans : %d\n",BMP_FILE_HEADER.plans);

	printf ("Bits par pixels : %d\n",BMP_FILE_HEADER.bpp);

	printf ("Taille de l'image : %d\n",BMP_FILE_HEADER.taille_image);

	int resolutionV=(BMP_FILE_HEADER.Vresolution*25.4/1000);

	printf ("Résolution verticale p/mm : %d\n",resolutionV);
	
	int resolutionH=(BMP_FILE_HEADER.Hresolution*25.4/1000);

	printf ("Résolution horizontale p/mm : %d\n",resolutionH);

	printf ("Nombre de couleurs (0 = toutes importantes) : %d\n",BMP_FILE_HEADER.nbr_couleur);

	printf ("Nombre de couleurs importantes (0 = toutes importantes) : %d\n",BMP_FILE_HEADER.nbr_couleur_importante);
	
return (EXIT_SUCCESS);

  }
/* après quelque tests on assure que ca ne marche que pour les fichiers bmp
FIN
*/

