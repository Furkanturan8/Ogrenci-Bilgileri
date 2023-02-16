#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int secim1;
struct Ogrenci{
	int numara;
	char ad[20];
	char soyad[20];
	int vize;
	int final;
};

FILE *veridosyasi;
char HATA_MESAJI[6];
int kullaniciyiat=0;

void kayitEkle(struct Ogrenci *ptr, int n){
	
	system("cls");
	int numara;
	int newno;
	char ad[20];
	char soyad[20];
	int vize;
	int final;
	int i=0;

	struct Ogrenci *kontrolPtr=ptr;
		
	while(i<n){
		
		printf("---%d.��rencinin Bilgileri---\n",i+1);
		printf("Numara:"); scanf("%d",&numara);
    	for(int g=0;g<n;g++){
	    	
			if(numara==kontrolPtr->numara){
	    		printf("\nBu numara ba�kas� taraf�ndan kullan�lmaktad�r.L�tfen bir daha ayn� numaray� girmeyiniz.\n\n");
	   
				kontrolPtr=ptr;
				
				printf("Farkli bir numara giriniz:"); scanf("%d",&newno);
				if(newno==numara){
					printf("\nHATALI ��LEM YAPTINIZ!!!\n\n");
					strcpy(HATA_MESAJI,"ERROR");
					goto son;
				}
				numara=newno;	
			}	
		}
		
		printf("�smi  :"); scanf("%s",ad);
   		printf("Soyad :"); scanf("%s",soyad);
		printf("Vizesi:"); scanf("%d",&vize);
		printf("Finali:"); scanf("%d",&final);

		ptr->numara=numara;
		ptr->vize=vize;
		strcpy(ptr->ad,ad);
		strcpy(ptr->soyad,soyad);
		ptr->final=final;
		 
		i++;
		ptr++;
	}
	printf("\nKay�t ��lemi Tamamlad�.Men�ye G�nderiliyorsunuz...\n\n");
	
	if(HATA_MESAJI=="ERROR"){
		son:
			kullaniciyiat=1;
			printf("KAYIT TAMAMLANAMADI!!!Program Kapan�yor...\n\n");
			printf("-L�tfen bir sonraki a��l��ta numaray� 2 kez hatal� girmeyiniz.\n-Aksi halde sistem sizi zararl� kullan�c� anlay�p atmaktad�r!!!\n-E�er yard�ma ihtiyac�n�z varsa personel numaras�n� aray�p ileti�ime ge�ebilirsiniz...\n");
			printf("\nYetkili personel numaras�: 0224 416 3245\n\n");
	}	
		
}

void ogrListele(struct Ogrenci *ptr, int n){

	int i=0;
	system("cls");
	
	printf("��RENC� L�STELER�");
	
	while(i<n){
		
		printf("\n---%d.��rencinin Bilgileri---\n",i+1);
		printf("Numara:%d\n",ptr->numara);
    	printf("�smi  :%s\n",ptr->ad);
	   	printf("Soyad :%s\n",ptr->soyad);
		printf("Vizesi:%d\n",ptr->vize);
	 	printf("Finali:%d\n",ptr->final);

		i++;
		ptr++;
	}
	printf("\nListeleme ��lemi Tamamlad�.Men�ye G�nderiliyorsunuz...\n\n");
	
}

void kayitGuncelle(struct Ogrenci *ptr, int n){
	
	system("cls");
	int numara;	
	char ad[20];
	char soyad[20];
	int vize;
	int final;
	int i=0;
	printf("G�ncellemek istedi�iniz ��rencinin numaras�n� giriniz:"); scanf("%d",&numara);
	
	int geridonus=0; 
	int h=n;
	while(i<n){
		if(numara!=ptr->numara){
			printf("G�ncelleme ��lemi Tamamlanamad�!!!\nMen�ye G�nderiliyorsunuz...\n\n");
			break;
		}				
		if(numara==ptr->numara){
			printf("%d numaral� ��rencinin bilgilerini giriniz..\n",numara);
			printf("�smi  :"); scanf("%s",ad);
			printf("Soyad�:"); scanf("%s",soyad);
			printf("Vizesi:"); scanf("%d",&vize);			
			printf("Finali:"); scanf("%d",&final);
			
			ptr->vize=vize;
			strcpy(ptr->ad,ad);
			strcpy(ptr->soyad,soyad);
		 	ptr->final=final;
		 	
			break;	
		}
			
		i++;
		ptr++;
	}
	if(geridonus==1)
		printf("\nG�ncelleme ��lemi Tamamlad�.Men�ye G�nderiliyorsunuz...\n\n");
	
}

void ortalamaHesapla(struct Ogrenci *ptr, int n){
	
	int numara;
	char ad[20];
	char soyad[20];
	int vize;
	int i=0;
	system("cls");
	
	printf("��RENC� ORTALAMASI\n\nNOT:��renci ortalamas�nda yap�lan i�lem �u �ekildedir:\n-Vizeden al�nan notun %%40'�\n-Finalden al�nan notun %%60'� toplan�r ve ki�i say�s�na b�l�n�r.\n");
	
	float ogrencilerinnotlaritoplami=0;
	while(i<n){
		
		ogrencilerinnotlaritoplami+=((ptr->vize)*0.4+(ptr->final)*0.6);
	 	
		i++;
		ptr++;
	}
	printf("\n��rencilerin Vize Ortalamas�: %f\n",ogrencilerinnotlaritoplami/n);
	printf("\nOrtalama Hesaplama ��lemi Tamamlad�.Men�ye G�nderiliyorsunuz...\n\n");
	
}

void enBasariliOgrenci(struct Ogrenci *ptr, int n){
	
	system("cls");
	int numara;
	char ad[20];
	char soyad[20];
	int vize;
	int final;
	float buyuk=0;
	float ortalama;
	int i=0;
	
	while(i<n){
		
		ortalama=((ptr->vize)*0.4+(ptr->final)*0.6);
		
		if(buyuk<ortalama){
			buyuk=ortalama;
			numara=ptr->numara;
			strcpy(ad,ptr->ad);
			strcpy(soyad,ptr->soyad);
			ortalama=buyuk;	
		}
		ptr++;
		i++;
	}
		printf("\n---En Ba�ar�l� ��rencinin Bilgileri---\n");
		printf("Numara:%d\n",numara); //ptr deki numara de�il yukar�daki de�i�kendeki numaray� yazaca��z
    	printf("�smi  :%s\n",ad);
	   	printf("Soyad :%s\n",soyad);
		printf("Ortalamas�:%f\n\n",buyuk);
	 	
	 	
}

int menu(){
	
	printf("<<<----MENU---->>>\n");
	printf("0-Bellek Artt�r\n1-Kay�t Ekleme\n2-Kay�t Listeleme \n3-Kay�t G�ncelleme \n4-S�n�f Ortalamas� Hesaplama\n5-Ortalamaya G�re En Ba�ar�l� ��renci\n");
	printf("6-��k��\n");
	printf("Tercihiniz:"); scanf("%d",&secim1);


	return secim1;
}

int main(){
	
	int n;
	setlocale(LC_ALL,"Turkish");
	printf("-----��renci Verileri Uygulamas�-----\n");
	printf("\nRAM'den ka� ��rencilik alan ayirmak istiyorsunuz:"); scanf("%d",&n);
	
	struct Ogrenci *ptr=(struct Ogrenci*) malloc (n * sizeof(struct Ogrenci));	
	
	printf("\n\n%d ki�ilik kontenjan eklenmi�tir.Duruma g�re men�den ekleme yapabilirsiniz!\n\n",n);
	secim1=menu();
	
	while(secim1!=6){
		
		if(secim1==0){
			int m;
			printf("G�ncel Durum: RAM'de %d ��rencilik alan var",n);
			
			printf("\nRAM'den ka� ��rencilik alan artt�rmak istiyorsunuz:"); scanf("%d",&m);
				
			n=n+m;
		
			ptr=(struct Ogrenci*) realloc (ptr,n);	
		
			printf("\n\n%d ki�ilik kontenjan eklenmi�tir.Duruma g�re men�den ekleme yapabilirsiniz!\n\n",n);
		}
	
		if(secim1==1){
			kayitEkle(ptr, n);	
			if(kullaniciyiat==1)
				return 0;
		}	
		else if(secim1==2)
			ogrListele(ptr, n);		

		else if(secim1==3)
			kayitGuncelle(ptr, n);	
		
		else if(secim1==4)
			ortalamaHesapla(ptr,n);
			
		else if(secim1==5)
			enBasariliOgrenci(ptr,n);
			
		else 
			printf("\nHATALI SE��M YAPTINIZ\n\n");		
	
		secim1=menu();			
	}
	
	
	
	
	printf("\nYetkili personel numaras�: 0224 416 3245\n\n");
	return 0;
}
