#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *ptr;
FILE *ptr2;

char uname[255], pass[255], str[255], find[100];
int i, n, o, s;
struct pengguna
{
  char nama[100], username[100], password[100], address[100], notel[100], email[100];
} user, admin;
struct kendaraan
{
  char merk[50], jenis[50];
  int perhari[50], hargasewa[50];
} kndr;

void tampilan();
void adminLogin(int l);
void adminMenu();
void adminListUser();
void adminInputKendaraan();
void adminUser();
void adminCariHapusUser();
void userSignUp();
void userLogin(int l);
void userMenu();
void userCheck();
void userInfoKendaraan();

void tampilanAwal()
{
  printf(" ====================================================================================\n");
  printf(" ============================== WELCOME B'DRIVE =====================================\n");
  printf(" ====================================================================================\n");
}
void tampilan()
{
  printf(" ====================================================================================\n");
  printf(" ================================== B'DRIVE =========================================\n");
  printf(" ====================================================================================\n");
}

void line()
{
  printf("\n ==================================================================================== \n\n");
}

void main()
{

  tampilanAwal();
  printf(" [1] USER \n");
  printf(" [2] ADMIN   \n");
  printf(" [0] EXIT    \n");
  line();
  printf(" PILIH MENU : ");
  scanf("%d", &o);
  getchar();
  if (o == 1)
  {
    system("cls");
    userCheck();
  }
  else if (o == 2)
  {
    system("cls");
    adminLogin(3);
  }
  else if (o == 0)
  {
    system("cls");
    printf("\n");
    line();
    printf("                                     SEE YOU                                       \n\n");
    printf("                           THANK YOU FOR USING B'DRIVE :)                         \n");
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
void adminLogin(int l)
{
  tampilan();
  printf("\t\t ADMIN - LOGIN \n\n");
  printf("Masukan Username : ");
  gets(admin.username);
  printf("Masukan Password : ");
  gets(admin.password);
  if (l > 1)
  {
    if (strcmp(admin.username, "admin") != 0)
    {
      printf("\n username salah \n\n");
      system("pause");
      system("cls");
      n = 1;
    }
    else if (strcmp(admin.password, "admin") != 0)
    {
      printf("\n password salah \n\n");
      system("pause");
      system("cls");
      n = 1;
    }
    else if (strcmp(admin.username, "admin") == 0 && strcmp(admin.password, "admin") == 0)
    {
      printf("\n Login berhasil \n\n");
      system("pause");
      system("cls");
      n = 2;
    }
  }
  else if (l == 1)
  {
    if (strcmp(admin.username, "admin") != 0 && strcmp(admin.password, "admin") != 0)
    {
      printf("\n username / password salah \n\n");
      system("pause");
      system("cls");
      n = 3;
    }
    else if (strcmp(admin.username, "admin") == 0 && strcmp(admin.password, "admin") == 0)
    {
      printf("\n Login berhasil \n\n");
      system("pause");
      system("cls");
      n = 2;
    }
  }
  switch (n)
  {
  case 1:
    adminLogin(l - 1);
    break;
  case 2:
    adminMenu();
    break;
  case 3:
    main();
    break;
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
  scanf("%d", &o);
  getchar();
  switch (o)
  {
  case 1:
    system("cls");
    adminListUser();
    break;
  case 2:
    system("cls");
    tampilan();
    printf("\t\t ADMIN - INPUT KENDARAAN \n\n");
    ptr = fopen("BDrive-kendaraan.dat", "ab");
    printf(" Banyak kendaraan yang akan di tambahkan : ");
    scanf("%d", &o);
    for (i = 0; i < o; i++)
    {
      getchar();
      printf("\n %d. Merk\t: ", i + 1);
      gets(kndr.merk);
      printf("\n    Jenis\t: ", i + 1);
      gets(kndr.jenis);
      printf("\n    Harga perhari\t: ");
      scanf("%d", &kndr.perhari);
      fwrite(&kndr, sizeof(kndr), 1, ptr);
    }
    fclose(ptr);
    printf("\n Kendaraan berhasil di tambahkan.\n");
    line();
    system("pause");
    system("cls");
    adminMenu();
    break;
  case 3:
    system("cls");
    adminCariHapusUser();
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

void adminListUser()
{
  tampilan();
  printf("\t\t ADMIN - DAFTAR USER \n\n");
  ptr = fopen("BDrive-user.dat", "rb");
  i = 1;
  while (fread(&user, sizeof(user), 1, ptr) == 1)
  {
    printf("%d. Nama Lengkap\t: %s \n", i, user.nama);
    printf("   Username\t: %s \n", user.username);
    printf("   Alamat\t: %s \n", user.address);
    printf("   No. Telpon\t: %s \n", user.notel);
    printf("   Email\t: %s \n", user.email);
    i++;
  }
  fclose(ptr);
  line();
  printf(" [0] Kembali \n\n");
  printf(" Pilih : ");
  scanf("%d", &n);
  switch (n)
  {
  case 0:
    system("cls");
    adminMenu();
    break;
  default:
    system("pause");
    system("cls");
    adminListUser();
  }
}

void adminCariHapusUser()
{
  tampilan();
  printf("\t\t ADMIN - Daftar User \n\n");
  ptr = fopen("BDrive-user.dat", "rb");
  s = 1;
  while (fread(&user, sizeof(user), 1, ptr) == 1)
  {
    printf(" %d. Nama Lengkap    : %s \n", s, user.nama);
    printf("  Nama Pengguna   : %s \n", user.username);
    printf("   Alamat\t: %s \n", user.address);
    printf("   No. Telpon\t: %s \n", user.notel);
    printf("   Email\t: %s \n", user.email);
    s++;
  }
  fclose(ptr);
  line();
  printf(" [1] Cari User \n [2] Hapus User \n  [0] Kembali \n\n");
  printf(" Pilih : ");
  scanf("%d", &n);
  switch (n)
  {
  case 0:
    system("cls");
    adminMenu();
    break;
  case 1:
    system("cls");
    adminCariUser();
    break;
  case 2:
    line();
    ptr = fopen("BDrive-user.dat", "rb");
    ptr2 = fopen("BDrive-user_new.dat", "wb");
    printf(" Masukan nama user yang ingin dihapus: ");
    getchar();
    gets(find);
    while (fread(&user, sizeof(user), 1, ptr) == 1)
    {
      if (strcmp(user.nama, find) != 0)
      {
        fwrite(&user, sizeof(user), 1, ptr2);
      }
      else
      {
        printf("\n Product berhasil dihapus. \n\n");
      }
    }
    fclose(ptr);
    fclose(ptr2);
    remove("BDrive-user.dat");
    rename("BDrive-user_new.dat", "BDrive-user.dat");
    system("pause");
    system("cls");
    adminUser();
    break;
  default:
    system("pause");
    system("cls");
    adminCariHapusUser();
  }
}

void adminCariUser()
{
  tampilan();
  printf("\t\t ADMIN - Cari User \n\n");
  ptr = fopen("BDrive-user.dat", "rb");
  ptr2 = fopen("BDrive-user_find.dat", "wb");
  getchar();
  printf("\n Silahkan masukkan username penjual yang dicari : \n ");
  gets(find);
  while (fread(&user, sizeof(user), 1, ptr) == 1)
  {
    if (strcmp(user.username, find) == 0)
    {
      fwrite(&user, sizeof(user), 1, ptr2);
    }
  }
  fclose(ptr);
  fclose(ptr2);

  ptr = fopen("Bdrive-user_find.dat", "rb");
  if (fread(&user, sizeof(user), 1, ptr) == 1)
  {
    printf("\n  Nama Lengkap    : %s %s \n", user.nama);
    printf("  Nama Pengguna   : %s \n", user.username);
  }
  else if (fgets(str, 255, ptr) == NULL)
  {
    printf("\n  Penjual tidak ditemukan. \n");
  }
  fclose(ptr);
  remove("BDrive-user_find.dat");
  line();
findx:
  printf(" [1] Cari User lain \n [0] Kembali \n\n");
  printf(" Pilih : ");
  scanf("%d", &n);
  switch (n)
  {
  case 0:
    system("cls");
    adminMenu();
    break;
  case 1:
    system("cls");
    adminCariUser();
    break;
  default:
    goto findx;
  }
}

// ============================= USER USER USER ==========================================
void userCheck()
{
  tampilan();
  printf("\t\t USER - CHECK \n\n");
  printf(" [1] Sign Up \n");
  printf(" [2] Login   \n");
  printf(" [0] Back    \n");
  line();
  printf(" PILIH MENU : ");
  scanf("%d", &o);
  getchar();
  if (o == 1)
  {
    system("cls");
    userSignUp();
  }
  else if (o == 2)
  {
    system("cls");
    userLogin(3);
  }
  else if (o == 0)
  {
    system("cls");
    main();
  }
  else
  {
    printf("\n Pilihan yang dimasukan salah ! \n\n");
    system("pause");
    system("cls");
    userCheck();
  }
}

void userSignUp()
{
  tampilan();
  printf("\t\t USER - SIGNUP \n\n");
  printf("Buat username\t: ");
  gets(uname);
  ptr = fopen("BDrive-user.dat", "rb");
  ptr2 = fopen("BDrive-userSignup.dat", "wb");
  while (fread(&user, sizeof(user), 1, ptr) == 1)
  {
    if (strcmp(user.username, uname) == 0)
    {
      fwrite(&user, sizeof(user), 1, ptr2);
    }
  }
  fclose(ptr);
  fclose(ptr2);
  ptr = fopen("BDrive-user.dat", "ab");
  ptr2 = fopen("BDrive-userSignup.dat", "rb");
  if (fgets(str, 255, ptr2) != NULL)
  {
    n = 0;
  }
  else if (fgets(str, 255, ptr2) == NULL)
  {
    strcpy(user.username, uname);
    printf(" Buat password\t: ");
    gets(user.password);
    printf("Nama\t\t: ");
    gets(user.nama);
    printf("No Telepon\t: ");
    gets(user.notel);
    printf("Alamat\t\t: ");
    gets(user.address);
    printf("Email\t\t: ");
    gets(user.email);
    fwrite(&user, sizeof(user), 1, ptr);
    n = 1;
  }
  fclose(ptr);
  fclose(ptr2);
  remove("BDrive-userSignup.dat");
  switch (n)
  {
  case 0:
    printf("\n username telah digunakan. \n");
    system("pause");
    system("cls");
    userSignUp();
    break;
  case 1:
    printf("\n Pendaftaran Berhasil. \n\n");
    printf(" [1] Login \n");
    printf(" [0] Kembali \n\n");
    printf(" Pilih : ");
    scanf("%d", &o);
    getchar();
    if (o == 1)
    {
      system("cls");
      userLogin(3);
    }
    else
    {
      system("cls");
      main();
    }
    break;
  }
}

void userLogin(int l)
{
  tampilan();
  ptr = fopen("BDrive-user.dat", "rb");
  ptr2 = fopen("BDrive-userLogin.dat", "wb");
  printf("\t\t USER - LOGIN \n\n");
  printf("Masukan Username\t: ");
  gets(uname);
  printf("Masukan Password\t: ");
  gets(pass);
  if (l >= 1)
  {
    while (fread(&user, sizeof(user), 1, ptr) == 1)
    {
      if (strcmp(user.username, uname) == 0)
      {
        fwrite(&user, sizeof(user), 1, ptr2);
      }
    }
    while (fgets(str, 255, ptr2) == NULL)
    {
      fwrite(&user, sizeof(user), 1, ptr2);
    }
  }
  fclose(ptr);
  fclose(ptr2);
  ptr = fopen("BDrive-user.dat", "rb");
  ptr2 = fopen("BDrive-userLogin.dat", "rb");
  if (l > 1)
  {
    while (fread(&user, sizeof(user), 1, ptr2) == 1)
    {
      if (strcmp(uname, user.username) != 0)
      {
        printf("\n username salah \n\n");
        system("pause");
        system("cls");
        n = 1;
        break;
      }
      else if (strcmp(pass, user.password) != 0)
      {
        printf("\n password salah \n\n");
        system("pause");
        system("cls");
        n = 1;
        break;
      }
      else if (strcmp(uname, user.username) == 0 && strcmp(pass, user.password) == 0)
      {
        printf("\n Login berhasil \n\n");
        system("pause");
        system("cls");
        n = 2;
        break;
      }
    }
  }
  else if (l == 1)
  {
    while (fread(&user, sizeof(user), 1, ptr2) == 1)
    {
      if (strcmp(uname, user.username) != 0 && strcmp(pass, user.password) != 0)
      {
        printf("\n username dan password salah \n\n");
        system("pause");
        system("cls");
        n = 3;
        break;
      }
      else if (strcmp(uname, user.username) == 0 && strcmp(pass, user.password) == 0)
      {
        printf("\n Login berhasil \n\n");
        system("pause");
        system("cls");
        n = 2;
        break;
      }
    }
  }
  fclose(ptr);
  fclose(ptr2);
  remove("BDrive-userLogin.dat");
  switch (n)
  {
  case 1:
    userLogin(l - 1);
    break;
  case 2:
    userMenu(uname);
    break;
  case 3:
    main();
    break;
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
  scanf("%d", &o);
  getchar();
  switch (o)
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
