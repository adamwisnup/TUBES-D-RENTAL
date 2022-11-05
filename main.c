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
  char nama[100], username[100], password[100], address[100];
} user, admin;

void tampilan();
void adminLogin();
void adminMenu();
void adminListUser();
void adminInputKendaraan();
void adminCariHapusUser();
void adminOrderKendaran();
void userMenu();
void userSignUp();
void userLogin();

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
    userMenu();
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
    tampilan();
    // adminListUser();
    break;
  case 2:
    system("cls");
    tampilan();
    // adminInputKendaraan();
    break;
  case 3:
    system("cls");
    tampilan();
    // adminCariHapusUser();
    break;
  case 4:
    system("cls");
    tampilan();
    // adminOrderUser();
    break;
  default:
    system("cls");
    tampilan();
    main();
    break;
  }
}

// =================== USER USER USER ==========================================
void userMenu()
{
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
    tampilan();
    userSignUp();
  }
  else if (pilih == 2)
  {
    system("cls");
    tampilan();
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
  printf("Nama     : ");
  gets(user.nama);
  printf("Alamat   : ");
  gets(user.address);
  printf("Username : ");
  gets(user.username);
  printf("Password : ");
  gets(user.password);
  fwrite(&user, sizeof(user), 1, ptr);
  fclose(ptr);
  printf("\nRegistrasi Sukes!\n");
  system("pause");
  system("cls");
  userMenu();
}

void userLogin()
{
  int n = 0;
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
      n = 1;
      break;
    }
  }
  fclose(ptr);
  if (n == 1)
  {
    printf("\nLogin Sukses, Selamat Datang %s!\n", user.nama);
    system("pause");
    system("cls");
    // userMenu();
  }
  else
  {
    printf("\nUsername / Password yang anda masukan salah!\n");
    system("pause");
    system("cls");
    userMenu();
  }
}
