#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct{
	int ogrenciNo;
	char ad[32];
	char soyad[32];
	int toplamDers;
	int ogrenciKredi;

}OGRENCI;

typedef struct{
	int dersiVerenID;
	char derskodu[16];
	char ders[32];
	int dersKredi;
	int kontenjan;
}DERS;

typedef struct{
	int ID;
	char adi[32];
	char soyadi[32];
	char unvan[32];
}OGRETIMUYESI;

typedef struct{
	int kaydedici;
	int ogrNo;
	char dersListeKodu[16];
	int durum;
	char zaman[32];
}OGRENCIDERSKAYIT;

int satirsay(char *dosyaadi){
	FILE *fp=fopen(dosyaadi,"r");
	int durum;
	int satir=0;
	if(fp==NULL){
	printf("hata olustu");}

	while(!feof(fp)){
		durum=fgetc(fp);
		if (durum=='\n'){
			satir++;
		}
	}
	fclose(fp);
	return satir;
}

OGRENCI *ogrdolas(){
		int x,sayac=0;
	FILE *Data;
    		char dosya[]="ogrenciler.txt";
        x=satirsay(dosya);
        	Data=fopen("ogrenciler.txt","r");
        	if(Data==NULL){
			printf("\n dosya olusturulurken HATA olustu");  }
        OGRENCI*str=(OGRENCI*)(malloc(x*sizeof(OGRENCI)));
    	while(sayac<x){
		fscanf(Data,"%d,%[^,],%[^,],%d,%d",&str[sayac].ogrenciNo,str[sayac].ad,str[sayac].soyad,&str[sayac].toplamDers,&str[sayac].ogrenciKredi);
		sayac++;
								}
	fclose(Data);
	return str;
}
OGRETIMUYESI *ogruyedolas(){
			int x,sayac=0;
	FILE *Data;
	    		char dosya[]="ogretimuyesi.txt";
        x=satirsay(dosya);
	Data=fopen("ogretimuyesi.txt","r");
	        	if(Data==NULL){
			printf("\n dosya olusturulurken HATA olustu");  }
	OGRETIMUYESI*stou=(OGRETIMUYESI*)(malloc(x*sizeof(OGRETIMUYESI)));
	    	while(sayac<x){
		fscanf(Data,"%d,%[^,],%[^,],%[^\n]",&stou[sayac].ID,stou[sayac].adi,stou[sayac].soyadi,stou[sayac].unvan);
		sayac++;
								}
	fclose(Data);
	return stou;
}
DERS *dersdolas(){
				int x,sayac=0;
	FILE *Data;
	    		char dosya[]="dersler.txt";
        x=satirsay(dosya);
	Data=fopen("dersler.txt","r");
		        	if(Data==NULL){
			printf("\n dosya olusturulurken HATA olustu");  }
			DERS*std=(DERS*)(malloc(x*sizeof(DERS)));
				    	while(sayac<x){
		fscanf(Data,"%d,%[^,],%[^,],%d,%d",&std[sayac].dersiVerenID,std[sayac].derskodu,std[sayac].ders,&std[sayac].dersKredi,&std[sayac].kontenjan);
		sayac++;
								}
	fclose(Data);
	return std;
}

OGRENCIDERSKAYIT *kayitdolas(){
					int x,sayac=0;
	FILE *Data;
	    		char dosya[]="ogrenciderskayit.txt";
        x=satirsay(dosya);
	Data=fopen("ogrenciderskayit.txt","r");
		        	if(Data==NULL){
			printf("\n dosya olusturulurken HATA olustu");  }
			OGRENCIDERSKAYIT*stk=(OGRENCIDERSKAYIT*)(malloc(x*sizeof(OGRENCIDERSKAYIT)));
						    	while(sayac<x){
	fscanf(Data,"%d,%d,%[^,],%d,%[^\n]",&stk[sayac].kaydedici,&stk[sayac].ogrNo,stk[sayac].dersListeKodu,&stk[sayac].durum,stk[sayac].zaman);
		sayac++;
								}
	fclose(Data);
	return stk;	
}

void guncelleme(int k){
	int gunc,numara,j,x;
		FILE *Data;
if(k==0){
		printf("\n guncellemek istediginiz ogrencinin mevcut numarasini giriniz ");
		scanf("%d",&numara);
		printf("\nguncellemek istediginiz ogrenci ozelliginin sayisini giriniz\n");
		printf("ogrenci no:1 / ad:2 /  soyad:3 /  aldigi kredi:4 /  aldigi ders sayisi:5 :");
		scanf("%d",&gunc);
		    		char dosya[]="ogrenciler.txt";
        x=satirsay(dosya);
        	OGRENCI *ogr=ogrdolas();
		Data=fopen("ogrenciler.txt","w+");
    		if(Data==NULL){
		printf("dosya olusturulamadý");	}
		for(j=0;j<x;j++){
			if(ogr[j].ogrenciNo==numara){
			if(gunc==1){
			printf("\n yeni ogrenci numarasi giriniz (bu degisiklik sistemsel sorunlar dogurabilir) ");
			scanf("%d",&ogr[j].ogrenciNo);			}
        else if(gunc==2){
			printf("\n ogrencinin yeni adini giriniz ");
			fflush(stdin);
			scanf("%[^\n]s",ogr[j].ad);			}
		else if(gunc==3){
			printf("\n ogrencinin yeni soyadini giriniz ");
			scanf("%s",ogr[j].soyad);				}
 		else if(gunc==4){
		printf("\n ogrencinin yeni kredi sayisini giriniz (DIKKAT bu hareket illegaldir tespit edilmesi durumunda hakkinizda yasal islem baslatilabilir) ");
		    scanf("%d",&ogr[j].ogrenciKredi);			}
		else if(gunc==5){
		printf("\n ogrencinin yeni toplam ders sayisini giriniz (DIKKAT bu hareket illegaldir tespit edilmesi durumunda hakkinizda yasal islem baslatilabilir) ");	
        scanf("%d",&ogr[j].toplamDers);		}   
		 			 }
        		fprintf(Data,"%d,%s,%s,%d,%d\n",ogr[j].ogrenciNo,ogr[j].ad,ogr[j].soyad,ogr[j].toplamDers,ogr[j].ogrenciKredi);			
		}
		printf("\n guncelleme basarili\n");
	}
else if(k==1){
		printf("\n guncellemek istediginiz ogretim uyesinin mevcut ID'sini giriniz ");
		scanf("%d",&numara);
		printf("\nguncellemek istediginiz ogretim uyesi ozelliginin sayisini giriniz\n");
		printf("ID:1 / ad:2 /  soyad:3 / unvan:4 :");
		scanf("%d",&gunc);
				char dosya[]="ogretimuyesi.txt";
        x=satirsay(dosya);
        OGRETIMUYESI *uye=ogruyedolas();
	Data=fopen("ogretimuyesi.txt","w+");
    		if(Data==NULL){
		printf("dosya olusturulamadi");	}
		for(j=0;j<x;j++){
			if(uye[j].ID==numara){
         	if(gunc==1){
			printf("\n yeni ogretim uyesi ID giriniz (bu degisiklik sistemsel sorunlar dogurabilir) ");
			scanf("%d",&uye[j].ID);			}
        else if(gunc==2){
			printf("\n ogretim uyesinin yeni adini giriniz ");
			fflush(stdin);
			scanf("%[^\n]s",uye[j].adi);			}
		else if(gunc==3){
			printf("\n ogretim uyesinin yeni soyadini giriniz ");
			scanf("%s",uye[j].soyadi);				}
 		else if(gunc==4){
			printf("\n ogretim uyesinin yeni unvanini giriniz (tebrik ederiz!) ");
			fflush(stdin);
			scanf("%[^\n]s",uye[j].unvan);		} 
			}
				fprintf(Data,"%d,%s,%s,%s\n",uye[j].ID,uye[j].adi,uye[j].soyadi,uye[j].unvan);
		}
			printf("\n guncelleme basarili\n");	
	}
else if(k==2){
	char cikart[16];
		   printf("\n duzenlemek istediginiz dersin kodunu giriniz (Buyuk kucuk harflere dikkat ediniz): ");
		   scanf("%s",cikart);
		printf("\nguncellemek istediginiz ders ozelliginin sayisini giriniz\n");
		printf("ogretim uyesi ID:1 / ders kodu:2 /  dersin adi:3 / kredi:4 / kontenjan:5 ");
		scanf("%d",&gunc);
	       		char dosya[]="dersler.txt";
        x=satirsay(dosya);
        DERS *der=dersdolas();
 	Data=fopen("dersler.txt","w+");
    		if(Data==NULL){
		printf(" dosya olusturulamadi ");	}  
		for(j=0;j<x;j++){
				if(strcmp(der[j].derskodu,cikart)==0){
			if(gunc==1){
			printf("\n dersin yeni hocasinin ID'sini giriniz");
			scanf("%d",&der[j].dersiVerenID);			}
			else if(gunc==2){
		printf("\n dersin yeni kodunu giriniz(DIKKAT donem bitmeden ders kodu degistirmek bazý sorunlar olusturabilir) ");
			scanf("%s",der[j].derskodu);				}
        else if(gunc==3){
			printf("\n dersin yeni adini giriniz ");
			fflush(stdin);
			scanf("%[^\n]s",der[j].ders);			}
 		else if(gunc==4){
		printf("\n dersin yeni kredi degerini giriniz ");
		    scanf("%d",&der[j].dersKredi);			}
		else if(gunc==5){
		printf("\n dersin yeni kontenjanini giriniz ");	
        scanf("%d",&der[j].kontenjan);		}
		 			 }	
	fprintf(Data,"%d,%s,%s,%d,%d\n",der[j].dersiVerenID,der[j].derskodu,der[j].ders,der[j].dersKredi,der[j].kontenjan);				  	
		}
				printf("\n guncelleme basarili\n");
	}
	else if(k==3){
		int tut=0;
		printf("\n ders cikartmak istediginiz ogrencinin numarasini giriniz ");
		scanf("%d",&numara);	
		char cikart[16];
		   printf("\n cikmak istediginiz dersin kodunu giriniz (Buyuk kucuk harflere dikkat ediniz): ");
		   scanf("%s",cikart);	
	    		char dosya[]="ogrenciderskayit.txt";
        x=satirsay(dosya);
        OGRENCIDERSKAYIT *kay=kayitdolas();
 	Data=fopen("ogrenciderskayit.txt","w+");
    		if(Data==NULL){
		printf("dosya olusturulamadi ");	} 	 
		for(j=0;j<x;j++){
			if(numara==kay[j].ogrNo){
				if(strcmp(kay[j].dersListeKodu,cikart)==0){
					kay[j].durum=1;
					tut=1;
				}
			}
			fprintf(Data,"%d,%d,%s,%d,%s\n",kay[j].kaydedici,kay[j].ogrNo,kay[j].dersListeKodu,kay[j].durum,kay[j].zaman);	
		}
		if(tut==1){
	printf("\n kayit basari ile silindi ");	}  
		else{
	printf("\n islem basarisiz ");	}
	           int kontogrenci,kontrol,kontders,kontrol2;
	            		char dosya3[]="dersler.txt";
        x=satirsay(dosya3);      
	    			j=0; 
					DERS *der=dersdolas();   
       	while(j<x){
        		if(strcmp(der[j].derskodu,cikart)==0){
                    kontrol2=1;
					kontders=j;  	}
				j++; }       
	           
   		char dosya2[]="ogrenciler.txt";	
		x=satirsay(dosya2);
	                   	OGRENCI *ogr=ogrdolas();
				j=0;
        	while(j<x){
        		if(numara==ogr[j].ogrenciNo){
                    kontrol=1; 
					kontogrenci=j; 	}
				j++; }
			ogr[kontogrenci].ogrenciKredi=ogr[kontogrenci].ogrenciKredi-der[kontders].dersKredi;
	ogr[kontogrenci].toplamDers=(ogr[kontogrenci].toplamDers)-1;
    der[kontders].kontenjan=der[kontders].kontenjan+1;
		FILE *Data2;
	Data2=fopen("ogrenciler.txt","w+");
	for(j=0;j<x;j++){ 
	fprintf(Data2,"%d,%s,%s,%d,%d\n",ogr[j].ogrenciNo,ogr[j].ad,ogr[j].soyad,ogr[j].toplamDers,ogr[j].ogrenciKredi);
	}
	fclose(Data2);
	if(kontrol==1){
    printf("\n %d numarali ogrencinin kredi degeri ve ders limiti guncellenmistir ",numara);
		}
    else{
    printf("\n onemsiz bir sorun olusmus olabilir ");	}
           		char dosya4[]="dersler.txt";
        x=satirsay(dosya4);
	Data2=fopen("dersler.txt","w+");
	for(j=0;j<x;j++){ 
	fprintf(Data2,"%d,%s,%s,%d,%d\n",der[j].dersiVerenID,der[j].derskodu,der[j].ders,der[j].dersKredi,der[j].kontenjan);
	}
	fclose(Data2);
    if(kontrol2==1){
    printf("\n dersin kontenjani guncellenmistir ");	}
    else{
    printf("\n onemsiz bir sorun olusmus olabilir ");	}
	}
	
	fclose(Data);
}

void ekle(int k, int makskredi, int maksders){
	int x,kontrol=0,j=0;
		FILE *Data;
	if (k==0){
	OGRENCI stu;
	printf("ogrenci no giriniz\n");
	scanf("%d",&stu.ogrenciNo);
	    		char dosya[]="ogrenciler.txt";
        x=satirsay(dosya);
        	OGRENCI *ogr=ogrdolas();
        	while(j<x){
        		if(stu.ogrenciNo==ogr[j].ogrenciNo){
            printf("\n bu numara daha once alinmis lutfen yeni bir numara giriniz");
            	scanf("%d",&stu.ogrenciNo);
			j=0;	}
				j++; }
	printf("ogrencinin adini giriniz\n");
    fflush(stdin);
    scanf("%[^\n]s",stu.ad);
	printf("ogrencinin soy adini giriniz\n");
	scanf("%s",stu.soyad);
	stu.toplamDers=0;
	stu.ogrenciKredi=0;
	FILE *stuData=fopen("ogrenciler.txt","a+");
	fprintf(stuData,"%d,%s,%s,%d,%d\n",stu.ogrenciNo,stu.ad,stu.soyad,stu.toplamDers,stu.ogrenciKredi);
	fclose(stuData);
		}
	else if (k==1){
	OGRETIMUYESI tea;
	printf("ogretim uyesi ID giriniz(sayi olarak orn:57,79)\n");
	scanf("%d",&tea.ID);
		char dosya[]="ogretimuyesi.txt";
        x=satirsay(dosya);
        OGRETIMUYESI *uye=ogruyedolas();
        	while(j<x){
        		if(tea.ID==uye[j].ID){
            printf("\n bu ID daha once alinmis lutfen yeni bir ID giriniz");
            	scanf("%d",&tea.ID);
         	j=0;  		}
			j++;
			}
	printf("ogretim uyesinin adini giriniz\n");
    fflush(stdin);
    scanf("%[^\n]s",tea.adi);
	printf("ogrencinin soy adini giriniz\n");
	scanf("%s",tea.soyadi);
	printf("ogretim uyesinin unvanini giriniz\n");
    fflush(stdin);
    scanf("%[^\n]s",tea.unvan);
	FILE *teaData=fopen("ogretimuyesi.txt","a+");
	fprintf(teaData,"%d,%s,%s,%s\n",tea.ID,tea.adi,tea.soyadi,tea.unvan);
	fclose(teaData);
	} 
	else if (k==2){
	DERS les;
	printf("Dersin Kodunu giriniz\n");
	scanf("%s",les.derskodu);
       		char dosya[]="dersler.txt";
        x=satirsay(dosya);
        DERS *der=dersdolas();   
       	while(j<x){
        		if(strcmp(der[j].derskodu,les.derskodu)==0){
            printf("\n bu ders kodu daha once alinmis lutfen yeni bir ders kodu giriniz");
			scanf("%s",les.derskodu);
			j=0;	}
		j++;	}
	printf("Dersin adini giriniz\n");
    fflush(stdin);
    scanf("%[^\n]s",les.ders);
	printf("Dersin kredisini giriniz\n");
	scanf("%d",&les.dersKredi);
	printf("Dersin kontenjanini giriniz\n");
    scanf("%d",&les.kontenjan);
  	printf("Dersi veren ogretim uyesinin IDsini giriniz\n");
    scanf("%d",&les.dersiVerenID);
	FILE *lesData=fopen("dersler.txt","a+");
	fprintf(lesData,"%d,%s,%s,%d,%d\n",les.dersiVerenID,les.derskodu,les.ders,les.dersKredi,les.kontenjan);
	fclose(lesData);
	}
	else if(k==3){
	OGRENCIDERSKAYIT sign;
		OGRENCI stu;
		int kontogrenci,kontders;
	printf("ogrenci no giriniz\n");
	scanf("%d",&stu.ogrenciNo);
	    		char dosya[]="ogrenciler.txt";
        x=satirsay(dosya);
        	OGRENCI *ogr=ogrdolas();
        	kontrol=0;
		while(kontrol==0){
			j=0;
        	while(j<x){
        		if(stu.ogrenciNo==ogr[j].ogrenciNo){
                    kontrol=1; 
					kontogrenci=j; 	}
				j++; }
			if(kontrol==1){
		printf("\n ogrenci bulundu devam edebilirsiniz\n");	}
			else{
		printf("\n ogrenci bulunamadi yeni numara giriniz: ");
			scanf("%d",&stu.ogrenciNo);	}
						}					
		
		DERS les;
	printf("Dersin Kodunu giriniz\n");
	scanf("%s",les.derskodu);
       		char dosya3[]="dersler.txt";
        x=satirsay(dosya3);
        DERS *der=dersdolas(); 
		        	kontrol=0;  
    		while(kontrol==0){
			j=0;    
       	while(j<x){
        		if(strcmp(der[j].derskodu,les.derskodu)==0){
                    kontrol=1;
					kontders=j;  	}
				j++; }
			if(kontrol==1){
		printf("\n ders kodu bulundu devam edebilirsiniz\n");	}
			else{
		printf("\n ders kodu bulunamadi yeni numara giriniz: ");
			scanf("%d",&les.derskodu);	}
						}	
						int girdik=0;
		if((ogr[kontogrenci].ogrenciKredi+der[kontders].dersKredi)<=(makskredi)){
	    girdik++;
	if(ogr[kontogrenci].toplamDers<maksders){
		girdik++;
		if(der[kontders].kontenjan>0){	
		girdik++;			
		strcpy(sign.dersListeKodu,les.derskodu);
			sign.ogrNo=stu.ogrenciNo;
		sign.durum=0;	
			    		char dosya2[]="ogrenciderskayit.txt";
	        x=satirsay(dosya2);
			sign.kaydedici=x+1;
				time_t t = time(NULL);
struct tm tm = *localtime(&t);
sprintf(sign.zaman, "%d-%02d-%02d/%02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
		FILE *signData=fopen("ogrenciderskayit.txt","a+");
	fprintf(signData,"%d,%d,%s,%d,%s\n",sign.kaydedici,sign.ogrNo,sign.dersListeKodu,sign.durum,sign.zaman);
	fclose(signData);	
	ogr[kontogrenci].ogrenciKredi=ogr[kontogrenci].ogrenciKredi+der[kontders].dersKredi;
	ogr[kontogrenci].toplamDers=(ogr[kontogrenci].toplamDers)+1;
	der[kontders].kontenjan=(der[kontders].kontenjan)-1;
	x=satirsay(dosya);
	Data=fopen("ogrenciler.txt","w+");
	for(j=0;j<x;j++){ 
	fprintf(Data,"%d,%s,%s,%d,%d\n",ogr[j].ogrenciNo,ogr[j].ad,ogr[j].soyad,ogr[j].toplamDers,ogr[j].ogrenciKredi);
	}
	fclose(Data);
		x=satirsay(dosya3);
	Data=fopen("dersler.txt","w+");	
	for(j=0;j<x;j++){
	fprintf(Data,"%d,%s,%s,%d,%d\n",der[j].dersiVerenID,der[j].derskodu,der[j].ders,der[j].dersKredi,der[j].kontenjan);	
	}
	fclose(Data);
			}
	}
}
    if(girdik!=3){
    printf("\n kayit basarisiz hata kodu: %d",(girdik+1));
	printf("\n kod 1:kredi yetersiz / kod 2:ders limiti asildi / kod 3:kontenjan dolu");	}

	}
	printf("\n ekleme islemi tamamlandi");
}




void silme(int k){
	int x,j,kontrol=0;
	FILE *Data;
	   	if (k==0){
	   		int atildin;
		   printf("okuldan atmak istediginiz ogrencinin numarasini giriniz: ");
		   scanf("%d",&atildin);
    		char dosya[]="ogrenciler.txt";
        x=satirsay(dosya);
        	OGRENCI *ogr=ogrdolas();
    		Data=fopen("ogrenciler.txt","w+");
    		if(Data==NULL){
		printf("dosya olusturulamadý");	}
        	for(j=0;j<x;j++){
        		if(atildin!=ogr[j].ogrenciNo){
        		fprintf(Data,"%d,%s,%s,%d,%d\n",ogr[j].ogrenciNo,ogr[j].ad,ogr[j].soyad,ogr[j].toplamDers,ogr[j].ogrenciKredi);
					kontrol++;
				}
			}
			if(kontrol==(x-1)){
			printf("\n %d numarali ogrenci okuldan atildi\n",atildin);			}
			else{
				printf("\n %d numarali ogrenci bulunamadi \n",atildin);
			}
		   }
	else if (k==1){
		   		int atildin;
		   printf("listeden cikartmak istediginiz ogretim uyesinin ID'sini giriniz: ");
		   scanf("%d",&atildin);
		char dosya[]="ogretimuyesi.txt";
        x=satirsay(dosya);
        OGRETIMUYESI *uye=ogruyedolas();
	Data=fopen("ogretimuyesi.txt","w+");
    		if(Data==NULL){
		printf("dosya olusturulamadi");	}
        	for(j=0;j<x;j++){
        		if(atildin!=uye[j].ID){
	fprintf(Data,"%d,%s,%s,%s\n",uye[j].ID,uye[j].adi,uye[j].soyadi,uye[j].unvan); 
					kontrol++;
				}
			}		
					if(kontrol==(x-1)){
			printf("\n %d ID'li ogretim uyesi cikartildi\n",atildin);			}
			else{
			printf("\n %d ID'li ogretim uyesi bulunamadi \n",atildin);
			}
	}
	
	else if (k==2){	
			   		char cikart[16];
		   printf("mufredattan cikartmak istediginiz dersin kodunu giriniz (Buyuk kucuk harflere dikkat ediniz): ");
		   scanf("%s",cikart);
		       		char dosya[]="dersler.txt";
        x=satirsay(dosya);
        DERS *der=dersdolas();
 	Data=fopen("dersler.txt","w+");
    		if(Data==NULL){
		printf("dosya olusturulamadi");	}   
       	for(j=0;j<x;j++){
        		if(strcmp(der[j].derskodu,cikart)!=0){
	fprintf(Data,"%d,%s,%s,%d,%d\n",der[j].dersiVerenID,der[j].derskodu,der[j].ders,der[j].dersKredi,der[j].kontenjan); 
					kontrol++;
				}
			}
	if(kontrol==(x-1)){
			printf("\n %s kodlu ders mufredattan cikartildi\n",cikart);			}
			else{
			printf("\n %s kodlu ders bulunamadi \n",cikart);
			}	 
	}
	fclose(Data);
}

void ogrUyeDersYazdir(int p, int id){
	int x,j;
	if(p!=111){
	printf("\n Derslerini goruntulemek istediginiz ogretim uyesinin ID'sini giriniz:  ");
	scanf("%d",&id); 	}
	       		char dosya[]="dersler.txt";
        x=satirsay(dosya);
        DERS *der=dersdolas(); 
        for(j=0;j<x;j++){
        	if(id==der[j].dersiVerenID){
	printf("\n Ders kodu: %s / Dersin adi: %s / Dersin kredi degeri: %d / Dersin mevcut kontenjani: %d",der[j].derskodu,der[j].ders,der[j].dersKredi,der[j].kontenjan);		}
		}
}


void DersiAlanOgrenciler(){
		int x,x2,j,i;
		char kod[16];
	printf("\n Ogrencilerini goruntulemek istediginiz dersin kodunu giriniz (Buyuk kucuk harflere dikkat edin):  ");
	scanf("%s",kod);
   		char dosya[]="ogrenciderskayit.txt";
        x=satirsay(dosya);
    OGRENCIDERSKAYIT *kay=kayitdolas();
       		char dosya2[]="ogrenciler.txt";
        x2=satirsay(dosya2);
        	OGRENCI *ogr=ogrdolas();
          for(j=0;j<x;j++){
        	if(strcmp(kod,kay[j].dersListeKodu)==0){
    	        for(i=0;i<x2;i++){
        	if(kay[j].ogrNo==ogr[i].ogrenciNo){
        		if(kay[j].durum==0)
  printf("\n NO: %d / isim: %s / soyisim: %s / aldigi ders sayisi: %d / harcadigi kredi adedi: %d ",ogr[i].ogrenciNo,ogr[i].ad,ogr[i].soyad,ogr[i].toplamDers,ogr[i].ogrenciKredi);
	  		} 
	        }
		    } 
			}

		printf("\n\n Dersi alan Tum ogrenciler yukaridadir. ");
}


void ogrenciDersYazdir(){
		int id,x,x2,j,i;
	printf("\n Derslerini goruntulemek istediginiz ogrencinin numarasini giriniz:  ");
	scanf("%d",&id);
   		char dosya[]="ogrenciderskayit.txt";
        x=satirsay(dosya);
    OGRENCIDERSKAYIT *kay=kayitdolas();
    DERS *der=dersdolas();  
       		char dosya2[]="dersler.txt";
        x2=satirsay(dosya2);

          for(j=0;j<x;j++){
        	if(id==kay[j].ogrNo){
    	        for(i=0;i<x2;i++){
        	if(strcmp(der[i].derskodu,kay[j].dersListeKodu)==0)  {
			if(kay[j].durum==0)  	
  printf("\n Ders kodu: %s / Dersin adi: %s / Dersin kredi degeri: %d / Dersin mevcut kontenjani: %d",der[i].derskodu,der[i].ders,der[i].dersKredi,der[i].kontenjan);
        }
    }
		} 
			}	
		printf("\n\n Ogrencinin aldigi tum dersler yukaridadir. ");
}

void IdSinifListesi(){
	int id;
	printf("\n Derslerini goruntulemek istediginiz ogretim uyesinin ID'sini giriniz:  ");
	scanf("%d",&id);
	ogrUyeDersYazdir(111,id);
printf("\n\n ogretim gorevlisinin mevcut dersleri yukaridadir. \n sinif listesi cikartmak istediginiz dersin kodunu giriniz(Buyuk kucuk harflere dikkat edin): ");
		int x,x2,j,i;
		char kod[16];
	scanf("%s",kod);
   		char dosya[]="ogrenciderskayit.txt";
        x=satirsay(dosya);
    OGRENCIDERSKAYIT *kay=kayitdolas();
       		char dosya2[]="ogrenciler.txt";
        x2=satirsay(dosya2);
        	OGRENCI *ogr=ogrdolas();
          char filename[50];
          filename[0]= '\0';
		   FILE *fw;
           strcat(filename,kod);
           strcat(filename,"_");
           strcat(filename,"SINIFLISTESI");
           strcat(filename,".txt");
           fw=fopen(filename,"w");	
          for(j=0;j<x;j++){
        	if(strcmp(kod,kay[j].dersListeKodu)==0){
    	        for(i=0;i<x2;i++){
        	if(kay[j].ogrNo==ogr[i].ogrenciNo){
        	if(kay[j].durum==0){
  printf("\n NO: %d / isim: %s / soyisim: %s / aldigi ders sayisi: %d / harcadigi kredi adedi %d ",ogr[i].ogrenciNo,ogr[i].ad,ogr[i].soyad,ogr[i].toplamDers,ogr[i].ogrenciKredi);
fprintf(fw,"NO: %d / isim: %s / soyisim: %s / aldigi ders sayisi: %d / harcadigi kredi adedi %d\n",ogr[i].ogrenciNo,ogr[i].ad,ogr[i].soyad,ogr[i].toplamDers,ogr[i].ogrenciKredi);
			}	
	  		} 
	        }
		    } 
			}
            fclose(fw);
            	   printf("\n\n %s olusturulmustur kontrol edebilirsiniz",filename);  
  
}


int main(int argc, char *argv[]) {
	int talep,x,maksders=3,makskredi=12,bitis=0,secim;
	printf("Ogrenci maksimum kredi degerini giriniz (hazirlanmis durumlari test icin '12' onerilir ama diger durumlar icin de sorunsuz calisiyor ):");
	scanf("%d",&makskredi);
	printf("\n Ogrenci alabilecegi maksimum ders sayisini giriniz ('4' onerilir ama diger degerler icin de sorunsuz calistirabilirsiniz):");
	scanf("%d",&maksders);
	system ("cls");
	while(bitis==0){
		printf("\n Ekleme islemleri sekmesi icin: 1 (ogrenci, ogretim uyesi, ders, sinif kayit olma)");
		printf("\n Silme islemleri sekmesi icin: 2 (ogrenci, ogretim uyesi, ders)");
		printf("\n Guncelleme islemleri sekmesi icin: 3 (ogrenci, ogretim uyesi, ders, sinif kayit aldirma)");
		printf("\n ID verilen ogretim uyesinin verdigi dersleri gormek icin : 4");
		printf("\n Ders kodu verilen derse kayitli olan ogrencileri gormek icin : 5");
		printf("\n Ogrenci numarasi verilen ogrencinin aldigi tum dersleri gormek icin : 6");
		printf("\n Sectiginiz ogrenciyi sectiginiz derse kayit etmek icin : 7");
		printf("\n Sectiginiz dersten kayit aldirmak icin : 8");
		printf("\n ID verilen hocanin bir dersinin sinif listesi cikartmak icin : 9");
		printf("\n hangi islem sekmesine girmek istiyorsunuz: ");
		scanf("%d",&talep);
		system ("cls");
		switch(talep){
			
			case 1:
				printf("\n Ogrenci eklemek icin: 0 \n Ogretim uyesi eklemek icin: 1");
				printf("\n Ders eklemek icin: 2 \n Ogrenciyi derse kayit etmek icin: 3");
				printf("\n Lutfen yapmak istediginiz islemi seciniz : ");
				scanf("%d",&secim);
				system ("cls");
                ekle(secim, makskredi, maksders);
				
			break;	
					
			case 2:
				printf("\n Ogrenci silmek icin: 0 \n Ogretim uyesi silmek icin: 1");
				printf("\n Ders silmek icin: 2 \n");
				printf("\n Lutfen yapmak istediginiz islemi seciniz : ");
				scanf("%d",&secim);
				system ("cls");	
				silme(secim);	
			break;
							
			case 3:
				printf("\n Ogrenci guncellemek icin: 0 \n Ogretim uyesi guncellemek icin: 1");
				printf("\n Ders guncellemek icin: 2 \n Ogrenci ders kayit aldirmak icin: 3");
				printf("\n Lutfen yapmak istediginiz islemi seciniz : ");
				scanf("%d",&secim);
				system ("cls");	
				guncelleme(secim);			
			break;	
					
			case 4:	
			system ("cls");
			ogrUyeDersYazdir(4,4);
			break;
			
			case 5:
			system ("cls");	
			DersiAlanOgrenciler();
			break;
			
	    	case 6:
			system ("cls");	
			ogrenciDersYazdir();
			break;
			
			case 7:	
				system ("cls");
                ekle(3, makskredi, maksders);
			break;
			
			case 8:	
		    	system ("cls");	
				guncelleme(3);
			break;
			
			case 9:
			system ("cls");			
			IdSinifListesi();	
			break;	
			
		}
		
		
	printf("\n\n yeni islem yapmak icin 0 (sifir) giriniz \n programi guvenli bir sekilde bitirmek icin 1 (bir) giriniz: ");
	scanf("%d",&bitis);	
	system ("cls");
	}
	
	return 0;
}

