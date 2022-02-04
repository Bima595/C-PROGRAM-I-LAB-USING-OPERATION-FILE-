#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <windows.h>

int h = 0;
void sc(char *kar)
{
	char str, karcek[99];
	int j = 0, i = 0;
	h = 0;
	strcpy(karcek, kar);
	for( i = 0, j = 0; str = karcek[i] = karcek[j]; j++)
	{
		if(str >= 32 && str <= 47 ||  str >= 58 && str <= 64 || str >= 91 && str <= 96 || str >= 123 && str <= 126)
		{
			i++;
			h = 1;
		}
	}
}

int main()
{
	int a = 0, b = 0, d, hapus, menu = 0, pilih, i = 1;
	char c[30], nimcek[30], search[30], nama1[30], nama2[30], nim[30], kelas[30], dosen[30];
	FILE*tambah, *read, *replace;
	printf("===PILIH MENU===");
	printf("\n1.INPUT DATA.\n");
	printf("2. SHOW DATA.\n");
	printf("3. UPDATE DATA.\n");
	printf("4. DELETE DATA.\n");
	printf("5. SEARCH DATA.\n");
	printf("6. EXIT DATA.\n");

	for(i = 0; 1 <= 1; i++)
	{
		printf("Masukkan Pilihan : ");
		scanf("%d", &pilih);
		printf("\n");

		switch(pilih)
		{
		case 1:

			system("cls");
nimblk:
			tambah = fopen("kumpulan_data.txt", "a");
			read = fopen("kumpulan_data.txt", "r");
			printf("==creat data==\n");
			printf("input nim praktikum\t\t: ");
			fflush(stdin);
			scanf("%s", nimcek);
			sc(nimcek);
			if(h == 1)
			{
				printf("NIM MU TIDAK SESUAI BUJANG !!!!!!\n");
				fclose(tambah);
				fclose(read);
				goto nimblk;
			}
			while(fscanf(read, "%[^#]#%[^#]#%[^#]#%[^\n]\n", nim, nama1, kelas, dosen) != EOF)
			{
				if(strcmp(nimcek, nim) == 0)
				{
					printf("NIM Yang anda Masukan sudah ke input\n");
					fclose(tambah);
					fclose(read);
					goto nimblk;
				}
			}
			strcpy(nim, nimcek);
			printf("nama depan : ");
			scanf(" %[^\n]s", nama1);
			fflush(stdin);
			printf("nama belakang : ");
			fflush(stdin);
			scanf("%[^\n]s", nama2);
			strcat(nama1, nama2);
			printf("nama praktikan : %s\n", nama1);
			fflush(stdin);
			printf("input kelas pemrogaman dasar\t: ");
			fflush(stdin);
			scanf("%[^\n]s", &kelas);
			printf("input nama dosen pemgampu\t: ");
			fflush(stdin);
			scanf(" %[^\n]s", &dosen);

			fprintf(tambah, "%s#", nim);
			fprintf(tambah, "%s#", nama1);
			fprintf(tambah, "%s#", strupr(kelas));
			fprintf(tambah, "%s\n", dosen);

			printf("=====================\n");
			printf("\nmenambah data\n");
			printf("\n=====================\n");

			fclose(tambah);
			fclose(read);
			break;

		case 2:
			system("cls");
			int b = 0;
			read = fopen("kumpulan_data.txt", "r");
			printf("==show data==\n");
			while(fscanf(read, "%[^#]#%[^#]#%[^#]#%[^\n]\n", nim, nama1, kelas, dosen) != EOF) //
			{
				b++;
				printf("%d. Nim praktikan			: %s\n", b, nim);
				printf("   Nama praktikan			: %s\n", nama1);
				printf("   Kelas Pemrogaman Dasar\t	: %s\n", kelas);
				printf("   Dosen Pengampu			: %s\n", dosen);
				printf("----------\n");
			}
			if(b == 0)
			{
				printf("\n=====================================================\n");
				printf("KAMU BELOM INPUT BUJANGGGGGG APA YANG MAU DI SHOWWWW !!!!!\n");
				printf("=======================================================\n");
			}
			fclose(read);
			break;

		case 3:
			printf("==update data==\n");
			replace = fopen("kumpulan_data_baru.txt", "w");
			read = fopen("kumpulan_data.txt", "r");
			printf("masukkan Nim yang ingin di update : ");
			scanf(" %s", &c);
			b = 0;
			while(fscanf(read, "%[^#]#%[^#]#%[^#]#%[^\n]\n", nim, nama1, kelas, dosen) != EOF)
			{
				if(strcmp(nim, c) == 0)
				{
					b++;
					printf("Nim			: %s\n", nim);
					printf("nama		: %s\n", nama1);
					printf("kelas		: %s\n", kelas);
					printf("dosen		: %s\n", dosen);
					printf("----------\n");
					printf("masukkan nim baru      : ");
					fflush(stdin);
					scanf("%s", nim);
					printf("masukkan nama depan baru     : ");
					fflush(stdin);
					scanf(" %[^\n]s", nama1);
					printf("masukkan nama belakang baru     : ");
					fflush(stdin);
					scanf(" %[^\n]s", nama2);
					strcat(nama1, nama2);
					printf("nama praktikan : %s\n", nama1);
					printf("masukkan kelas baru    : ");
					fflush(stdin);
					scanf("%[^\n]s", kelas);
					printf("masukkan dosen baru    : ");
					fflush(stdin);
					scanf(" %[^\n]s", dosen);

					fprintf(replace, "%s#", nim);
					fprintf(replace, "%s#", nama1);
					fprintf(replace, "%s#", kelas);
					fprintf(replace, "%s\n", dosen);
				}
				else
				{
					fprintf(replace, "%s#", nim);
					fprintf(replace, "%s#", nama1);
					fprintf(replace, "%s#", kelas);
					fprintf(replace, "%s\n", dosen);
				}
			}
			if(b == 0)
			{
				printf("\n=====================================================\n");
				printf("KAMU BELOM INPUT BUJANGGGGGG APA YANG MAU DI UPDATEDDDD !!!!!\n");
				printf("=======================================================\n");
			}
			fclose(replace);
			fclose(read);
			remove("kumpulan_data.txt");
			rename("kumpulan_data_baru.txt", "kumpulan_data.txt");
			break;

		case 4:
			replace = fopen("kumpulan_data_baru.txt", "w");
			read = fopen("kumpulan_data.txt", "r");
			printf(" === hapus data ===\n");
			printf("masukkan NIM yang ingin di delete : ");
			scanf("%s", c);
			while(fscanf(read, "%[^#]#%[^#]#%[^#]#%[^\n]\n", nim, nama1, kelas, dosen) != EOF)
			{
				if(strcmp(nim, c) != 0)
				{
					fprintf(replace, "%s#", nim);
					fprintf(replace, "%s#", nama1);
					fprintf(replace, "%s#", kelas);
					fprintf(replace, "%s\n", dosen);
				}
			}
			if(c == 0)
			{
				printf("\n=====================================================\n");
				printf("KAMU BELOM INPUT BUJANGGGGGG NIM MU TIDAK ADAAAAA !!!!!\n");
				printf("=======================================================\n");
			}
			fclose(replace);
			fclose(read);
			remove("kumpulan_data.txt");
			rename("kumpulan_data_baru.txt", "kumpulan_data.txt");
			break;

		case 5:
			read = fopen("kumpulan_data.txt", "r");
			printf(" === Search Data ===\n");
			printf(" Masukkan NIM Praktikan : ");
			scanf("%s", search);
			b = 0;
			while(fscanf(read, "%[^#]#%[^#]#%[^#]#%[^\n]\n", nim, nama1, kelas, dosen) != EOF)
			{
				if(strcmp(search, nim) == 0)
				{
					b++;
					printf(" Nim Praktikan\t\t: %s\n", nim);
					printf(" Nama Praktikan\t\t: %s\n", nama1);
					printf(" Kelas Pemograman Dasar\t: %s\n", kelas);
					printf(" Dosen Pengampu\t\t: %s\n", dosen);
				}
			}
			if(b == 0)
			{
				printf("\n=====================================================\n");
				printf("KAMU BELOM INPUT BUJANGGGGGG NIM MU TIDAK ADAAAAA !!!!!\n");
				printf("=======================================================\n");
			}
			fclose(read);
			break;

		case 6:
			printf("EXIT.......\n");
			return 0;
		}
	}
	return 0;
}
