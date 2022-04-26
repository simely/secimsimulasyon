#include <stdio.h>
#include <stdlib.h>

int j,k,c,sayac,m,fnf,say,sayac2,o,mv_Kont,t,n,i,a,toplam=0,mv_Toplam=0;
float temp,temp2,temp3;
char temp4;
char parti_Ad[6]={'A','B','C','D','E','F'};
char sirali_Parti[6]={'A','B','C','D','E','F'};
char mv_Parti[6]={'A','B','C','D','E','F'};
float yy[6]={0,0,0,0,0,0};
float yy_2[6]={0,0,0,0,0,0};
int il_Kodu[5]={0,0,0,0,0};
float MV_Sayisi[6]={0,0,0,0,0,0};
float oy_Sayisi[6]={0,0,0,0,0,0};
int TG_parti_Veri[6][3]; // A-B-C-D-E-F partilerinin verilerinin saklandýðý dizi. (Birincilik,ToplamOy,ToplamMv)
float gecici_Oy[6]={0,0,0,0,0,0};
float mv_2[6]={0,0,0,0,0,0};

float dizi_Kopyala(float d1[],float d2[]) //float d1 dizisini d2 dizisine kopyalar.
{
	for (c=0; c<6; c++)
	{
		d2[c]=d1[c];
	}
}

char ch_dizi_Kopyala(char d1[],char d2[]) //char d1 dizisini d2 dizisine kopyalar.
{
	for (c=0; c<6; c++)
	{
		d2[c]=d1[c];
	}
}

float sirala(float dizi[],char gecici_Parti[]) // diziyi oy sýralarýna göre sýralarken ayný zamanda partileri de sýralar.
{
	for(k=0; k<6; k++)
	{
		for(j=0; j<5; j++)
		{
			if (dizi[j]<dizi[j+1])
			{
				temp=dizi[j];
				dizi[j]=dizi[j+1];
				dizi[j+1]=temp;
				
				temp4=gecici_Parti[j];
				gecici_Parti[j]=gecici_Parti[j+1];
				gecici_Parti[j+1]=temp4;
			}	
		}
	}
}


float topla(float kekw[]) 
{
	t=0;
	for (o=0; o<6; o++)
	{
		t+=kekw[o];
	}
return t;
}


float mv_Sirala()  //Milletvekili kontenjaný bitene ya da oy sayýsý - lere düþene kadar milletvekili daðýtmasý yapýlýr.
{
	
	while (mv_Kont!=0&&gecici_Oy[0]>0)
	{
		
		if (mv_Parti[0]=='A')
		{
			TG_parti_Veri[0][2]+=1;
			mv_2[0]+=1;
			gecici_Oy[0]/=2;
			sirala(gecici_Oy,mv_Parti);
			mv_Kont-=1;
		}
		else if (mv_Parti[0]=='B')
		{
			TG_parti_Veri[1][2]+=1;
			mv_2[1]+=1;
			gecici_Oy[0]/=2;
			sirala(gecici_Oy,mv_Parti);
			mv_Kont-=1;
		}
		else if (mv_Parti[0]=='C')
		{
			TG_parti_Veri[2][2]+=1;
			mv_2[2]+=1;
			gecici_Oy[0]/=2;
			sirala(gecici_Oy,mv_Parti);
			mv_Kont-=1;
		}
		else if (mv_Parti[0]=='D')
		{
			TG_parti_Veri[3][2]+=1;
			mv_2[3]+=1;
			gecici_Oy[0]/=2;
			sirala(gecici_Oy,mv_Parti);
			mv_Kont-=1;
		}
		else if (mv_Parti[0]=='E')
		{
			TG_parti_Veri[4][2]+=1;
			mv_2[4]+=1;
			gecici_Oy[0]/=2;
			sirala(gecici_Oy,mv_Parti);
			mv_Kont-=1;
		}
		else if (mv_Parti[0]=='F')
		{
			TG_parti_Veri[5][2]+=1;
			mv_2[5]+=1;
			gecici_Oy[0]/=2;
			sirala(gecici_Oy,mv_Parti);
			mv_Kont-=1;
		}
	}
	
	for (a=0; a<6; a++)
	{
		for (c=0; c<6; c++)
		{
			if(sirali_Parti[a]==parti_Ad[c])
			{
				MV_Sayisi[a]=mv_2[c];
			}
		}
	}
}

int birincilik_Ekle(char dizi[])  // Her ilden sonra birinci olan partiyi listesine ekler.
{
	if (dizi[0]=='A')
	{
		TG_parti_Veri[0][0]+=1;
	}
	else if (dizi[0]=='B')
	{
		TG_parti_Veri[1][0]+=1;
	}
	else if (dizi[0]=='C')
	{
		TG_parti_Veri[2][0]+=1;
	}
	else if (dizi[0]=='D')
	{
		TG_parti_Veri[3][0]+=1;
	}
	else if (dizi[0]=='E')
	{
		TG_parti_Veri[4][0]+=1;
	}
	else if (dizi[0]=='F')
	{
		TG_parti_Veri[5][0]+=1;
	}
}

int main () // Ana kod satýrý.
{	
	
   for (sayac=0; sayac<5; sayac++)
   {
   	
   	printf("Il Kodunu Girin:");
   	scanf("%d",&il_Kodu[sayac]);
   	printf("Milletvekili kontenjanini girin: ");
   	scanf("%d",&mv_Kont);
   	
   	for (m=0; m<6; m++)
   	{
   		printf("%c Partisinin Oy sayisini girin: ",parti_Ad[m]);
   		scanf("%f",&oy_Sayisi[m]);
   		TG_parti_Veri[m][1]+=oy_Sayisi[m];
   		
	}  
			  		  
	sirala(oy_Sayisi,sirali_Parti);
	dizi_Kopyala(oy_Sayisi,gecici_Oy);
	ch_dizi_Kopyala(sirali_Parti,mv_Parti);
	
	for (a=0; a<6; a++)
	{
		temp3=topla(oy_Sayisi);
		temp2=oy_Sayisi[a];
		temp2=temp2*100;
		yy[a]=temp2/temp3;
	}
	
	printf("\n");
	printf("Il kodu\t:%d\nToplam Oy Sayisi\t:%.0f\nMilletvekili Kontenjani\t:%d\n\n",il_Kodu[sayac],topla(oy_Sayisi),mv_Kont);
	mv_Sirala();
	printf("\t\tOy Sayisi\tOy Yuzdesi\tMV Sayisi\n");
	printf("\t\t---------\t----------\t---------\n");
	toplam+=topla(oy_Sayisi);
	mv_Toplam+=topla(MV_Sayisi);
	
	for (fnf=0; fnf<6; fnf++)
	{
		printf("%c Partisi\t %.0f\t\t%.2f\t\t%.0f\n",sirali_Parti[fnf],oy_Sayisi[fnf],yy[fnf],MV_Sayisi[fnf]);
		mv_2[fnf]=0;
		oy_Sayisi[fnf]=0;
		yy[fnf]=0;
	}
	
	birincilik_Ekle(sirali_Parti);
	
	for (k=0; k<6; k++)
	{
		sirali_Parti[k]=parti_Ad[k];
	}
	
	printf("\nDevam etmek icin bir tusa basiniz...\n");
	getch();

	}

	printf("\nTurkiye Geneli\n--------------\n");
	printf("\t\tOy Sayisi\tOy Yuzdesi\tMV Sayisi\tMV Yuzdesi\tBirincilik Sayisi\n");
	printf("\t\t---------\t----------\t---------\t----------\t-----------------\n");
	
	for (a=0; a<6; a++)
	{
		temp3=toplam;
		temp2=TG_parti_Veri[a][1];
		temp2=temp2*100;
		yy[a]=temp2/temp3;
		temp3=mv_Toplam;
		temp2=TG_parti_Veri[a][2];
		temp2=temp2*100;
		yy_2[a]=temp2/temp3;
		printf("%c Partisi\t %d\t\t%.2f\t\t%d\t\t%.2f\t\t%d\n",parti_Ad[a],TG_parti_Veri[a][1],yy[a],TG_parti_Veri[a][2],yy_2[a],TG_parti_Veri[a][0]);
		MV_Sayisi[a]=TG_parti_Veri[a][2];
		
	}
	
	sirala(MV_Sayisi,parti_Ad);
	printf("\nIktidar partisi %.0f Milletvekili ile %c...\n",MV_Sayisi[0],parti_Ad[0]);
	printf("Ana muhalefet partisi %.0f Millet vekili ile %c...\n",MV_Sayisi[1],parti_Ad[1]);
	
}

