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
		
		printf("---%d.Öðrencinin Bilgileri---\n",i+1);
		printf("Numara:"); scanf("%d",&numara);
    	for(int g=0;g<n;g++){
	    	
			if(numara==kontrolPtr->numara){
	    		printf("\nBu numara baþkasý tarafýndan kullanýlmaktadýr.Lütfen bir daha ayný numarayý girmeyiniz.\n\n");
	   
				kontrolPtr=ptr;
				
				printf("Farkli bir numara giriniz:"); scanf("%d",&newno);
				if(newno==numara){
					printf("\nHATALI ÝÞLEM YAPTINIZ!!!\n\n");
					strcpy(HATA_MESAJI,"ERROR");
					goto son;
				}
				numara=newno;	
			}	
		}
		
		printf("Ýsmi  :"); scanf("%s",ad);
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
	printf("\nKayýt Ýþlemi Tamamladý.Menüye Gönderiliyorsunuz...\n\n");
	
	if(HATA_MESAJI=="ERROR"){
		son:
			kullaniciyiat=1;
			printf("KAYIT TAMAMLANAMADI!!!Program Kapanýyor...\n\n");
			printf("-Lütfen bir sonraki açýlýþta numarayý 2 kez hatalý girmeyiniz.\n-Aksi halde sistem sizi zararlý kullanýcý anlayýp atmaktadýr!!!\n-Eðer yardýma ihtiyacýnýz varsa personel numarasýný arayýp iletiþime geçebilirsiniz...\n");
			printf("\nYetkili personel numarasý: 0224 416 3245\n\n");
	}	
		
}

void ogrListele(struct Ogrenci *ptr, int n){

	int i=0;
	system("cls");
	
	printf("ÖÐRENCÝ LÝSTELERÝ");
	
	while(i<n){
		
		printf("\n---%d.Öðrencinin Bilgileri---\n",i+1);
		printf("Numara:%d\n",ptr->numara);
    	printf("Ýsmi  :%s\n",ptr->ad);
	   	printf("Soyad :%s\n",ptr->soyad);
		printf("Vizesi:%d\n",ptr->vize);
	 	printf("Finali:%d\n",ptr->final);

		i++;
		ptr++;
	}
	printf("\nListeleme Ýþlemi Tamamladý.Menüye Gönderiliyorsunuz...\n\n");
	
}

void kayitGuncelle(struct Ogrenci *ptr, int n){
	
	system("cls");
	int numara;	
	char ad[20];
	char soyad[20];
	int vize;
	int final;
	int i=0;
	printf("Güncellemek istediðiniz öðrencinin numarasýný giriniz:"); scanf("%d",&numara);
	
	int geridonus=0; 
	int h=n;
	while(i<n){
		if(numara!=ptr->numara){
			printf("Güncelleme Ýþlemi Tamamlanamadý!!!\nMenüye Gönderiliyorsunuz...\n\n");
			break;
		}				
		if(numara==ptr->numara){
			printf("%d numaralý öðrencinin bilgilerini giriniz..\n",numara);
			printf("Ýsmi  :"); scanf("%s",ad);
			printf("Soyadý:"); scanf("%s",soyad);
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
		printf("\nGüncelleme Ýþlemi Tamamladý.Menüye Gönderiliyorsunuz...\n\n");
	
}

void ortalamaHesapla(struct Ogrenci *ptr, int n){
	
	int numara;
	char ad[20];
	char soyad[20];
	int vize;
	int i=0;
	system("cls");
	
	printf("ÖÐRENCÝ ORTALAMASI\n\nNOT:Öðrenci ortalamasýnda yapýlan iþlem þu þekildedir:\n-Vizeden alýnan notun %%40'ý\n-Finalden alýnan notun %%60'ý toplanýr ve kiþi sayýsýna bölünür.\n");
	
	float ogrencilerinnotlaritoplami=0;
	while(i<n){
		
		ogrencilerinnotlaritoplami+=((ptr->vize)*0.4+(ptr->final)*0.6);
	 	
		i++;
		ptr++;
	}
	printf("\nÖðrencilerin Vize Ortalamasý: %f\n",ogrencilerinnotlaritoplami/n);
	printf("\nOrtalama Hesaplama Ýþlemi Tamamladý.Menüye Gönderiliyorsunuz...\n\n");
	
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
		printf("\n---En Baþarýlý Öðrencinin Bilgileri---\n");
		printf("Numara:%d\n",numara); //ptr deki numara deðil yukarýdaki deðiþkendeki numarayý yazacaðýz
    	printf("Ýsmi  :%s\n",ad);
	   	printf("Soyad :%s\n",soyad);
		printf("Ortalamasý:%f\n\n",buyuk);
	 	
	 	
}

int menu(){
	
	printf("<<<----MENU---->>>\n");
	printf("0-Bellek Arttýr\n1-Kayýt Ekleme\n2-Kayýt Listeleme \n3-Kayýt Güncelleme \n4-Sýnýf Ortalamasý Hesaplama\n5-Ortalamaya Göre En Baþarýlý Öðrenci\n");
	printf("6-Çýkýþ\n");
	printf("Tercihiniz:"); scanf("%d",&secim1);


	return secim1;
}

int main(){
	
	int n;
	setlocale(LC_ALL,"Turkish");
	printf("-----Öðrenci Verileri Uygulamasý-----\n");
	printf("\nRAM'den kaç öðrencilik alan ayirmak istiyorsunuz:"); scanf("%d",&n);
	
	struct Ogrenci *ptr=(struct Ogrenci*) malloc (n * sizeof(struct Ogrenci));	
	
	printf("\n\n%d kiþilik kontenjan eklenmiþtir.Duruma göre menüden ekleme yapabilirsiniz!\n\n",n);
	secim1=menu();
	
	while(secim1!=6){
		
		if(secim1==0){
			int m;
			printf("Güncel Durum: RAM'de %d öðrencilik alan var",n);
			
			printf("\nRAM'den kaç öðrencilik alan arttýrmak istiyorsunuz:"); scanf("%d",&m);
				
			n=n+m;
		
			ptr=(struct Ogrenci*) realloc (ptr,n);	
		
			printf("\n\n%d kiþilik kontenjan eklenmiþtir.Duruma göre menüden ekleme yapabilirsiniz!\n\n",n);
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
			printf("\nHATALI SEÇÝM YAPTINIZ\n\n");		
	
		secim1=menu();			
	}
	
	
	
	
	printf("\nYetkili personel numarasý: 0224 416 3245\n\n");
	return 0;
}
