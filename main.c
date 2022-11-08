#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *ptr;
FILE *ptr2;
FILE *temp;

int pilih;
char uname[100], pass[100];

struct pengguna
{
  char nama[100], username[100], password[100], address[100], notel[100], email[100];
} user, admin;

void tampilan();
void adminLogin();
void adminMenu();
void adminListUser();
void adminInputKendaraan();
void adminCariHapusUser();
void adminOrderKendaran();
void userSignUp();
void userLogin();
void userMenu();
void userCheck();

void tampilan()
{
  printf(" ====================================================================================\n");
  printf(" ================================== D'RENTAL ========================================\n");
  printf(" ====================================================================================\n");
}

void line()
{
  printf("\n ==================================================================================== \n\n");
}

void main()
{

  tampilan();
  printf(" [1] USER \n");
  printf(" [2] ADMIN   \n");
  printf(" [0] EXIT    \n");
  line();
  printf(" PILIH MENU : ");
  scanf("%d", &pilih);
  getchar();
  if (pilih == 1)
  {
    system("cls");
    tampilan();
    userCheck();
  }
  else if (pilih == 2)
  {
    system("cls");
    tampilan();
    adminLogin();
  }
  else if (pilih == 0)
  {
    system("cls");
    printf("\n");
    line();
    printf("                                     SEE YOU                                       \n\n");
    printf("                           THANK YOU FOR USING D'RENTAL :)                         \n");
    line();
  }
  else
  {
    printf("\n Pilihan yang dimasukan salah ! \n\n");
    system("pause");
    system("cls");
    main();
  }
}

// ================== ADMIN ADMIN ADMIN ========================================
void adminLogin()
{
  printf("\t\t ADMIN - LOGIN \n\n");
  printf(" username : ");
  gets(admin.username);
  printf(" password : ");
  gets(admin.password);
  if (strcmp(admin.username, "admin") == 0 && strcmp(admin.password, "admin") == 0)
  {
    system("cls");
    adminMenu();
  }
  else
  {
    printf("\n\n username dan password salah. \n\n");
    system("pause");
    system("cls");
    main();
  }
}

void adminMenu()
{
  printf("\t\t ADMIN - MENU \n\n");
  printf(" [1] List Daftar User \n");
  printf(" [2] Input List Kendaraan   \n");
  printf(" [3] Cari dan Hapus Akun User    \n");
  printf(" [4] Orderan User    \n");
  printf(" [0] Log Out    \n");
  line();
  printf(" PILIH MENU : ");
  scanf("%d", &pilih);
  getchar();
  switch (pilih)
  {
  case 1:
    system("cls");
    // adminListUser();
    break;
  case 2:
    system("cls");
    // adminInputKendaraan();
    break;
  case 3:
    system("cls");
    // adminCariHapusUser();
    break;
  case 4:
    system("cls");
    // adminOrderUser();
    break;
  default:
    system("cls");
    main();
    break;
  }
}

// =================== USER USER USER ==========================================
void userCheck()
{
  tampilan();
  printf("\t\t USER - CHECK \n\n");
  printf(" [1] Sign Up \n");
  printf(" [2] Login   \n");
  printf(" [0] Back    \n");
  line();
  printf(" PILIH MENU : ");
  scanf("%d", &pilih);
  getchar();
  if (pilih == 1)
  {
    system("cls");
    userSignUp();
  }
  else if (pilih == 2)
  {
    system("cls");
    userLogin();
  }
  else if (pilih == 0)
  {
    system("cls");
    main();
  }
  else
  {
    printf("\n Pilihan yang dimasukan salah ! \n\n");
    system("pause");
    system("cls");
    userMenu();
  }
}
void userSignUp()
{
  ptr = fopen("userData.dat", "ab");
  printf("\t\t USER - REGISTER \n\n");
  printf("Nama\t\t: ");
  gets(user.nama);
  printf("No Telepon\t: ");
  gets(user.notel);
  printf("Alamat\t\t: ");
  gets(user.address);
  printf("Email\t\t: ");
  gets(user.email);
  printf("Username\t: ");
  gets(user.username);
  printf("Password\t: ");
  gets(user.password);
  fwrite(&user, sizeof(user), 1, ptr);
  fclose(ptr);
  printf("\nRegistrasi Sukes! Selamat Datang %s!\n", user.nama);
  system("pause");
  system("cls");
  userMenu();
}

void userLogin()
{
  int i;
  char uname[50], pass[50];

  for (i = 3; i >= 1; i--)
  {
    ptr = fopen("userData.dat", "rb");
    printf("\t\t USER - LOGIN \n\n");
    printf("Username : ");
    gets(uname);
    printf("Password : ");
    gets(pass);
    // check username & password
    while (fread(&user, sizeof(user), 1, ptr) == 1)
    {
      if (strcmp(uname, user.username) == 0 && strcmp(pass, user.password) == 0)
      {
        printf("\nLogin Sukses, Selamat Datang %s!\n", user.nama);
        system("pause");
        system("cls");
        userMenu();
        i = i * 0;
      }
      else
      {
        printf("\nUsername / Password yang anda masukan salah!\n");
        if (i > 1)
        {
          printf("Silahkan coba lagi, kesempatan Anda tersisa %d lagi\n", i - 1);
          system("pause");
          system("cls");
        }
        else
        {
          printf("Kesempatan Anda sudah habis\n");
          system("pause");
          system("cls");
          userCheck();
        }
      }
    }
    fclose(ptr);
  }
}

void userMenu()
{
  tampilan();
  printf("\t\t USER - MENU \n\n");
  printf(" [1] Info Kendaraan \n");
  printf(" [2] Hasil Pesanan   \n");
  printf(" [0] Log Out    \n");
  line();
  printf(" PILIH MENU : ");
  scanf("%d", &pilih);
  getchar();
  switch (pilih)
  {
  case 1:
    system("cls");
    // userInfoKendaraan();
    break;
  case 2:
    system("cls");
    // userHasilPesanan();
    break;
  default:
    system("cls");
    main();
    break;
  }
}
