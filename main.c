#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *ptr;
FILE *ptr2;
FILE *order;

char uname[255], pass[255], str[255], find[100], jenis[100];
int i, n, o, s, j, total;
struct pengguna
{
  char nama[100], username[100], password[100], address[100], notel[100], email[100];
} user, admin;

struct kendaraan
{
  char namakendaraan[50], jenis[50], jaminan[50], nama[100], address[100], notel[100], email[100];
  int perhari, harisewa;
} kndr, ordr, temp[50], temp2;

void tampilan();
void adminLogin(int l);
void adminMenu();
void adminListUser();
void adminListKendaraan();
void adminCariUser();
void adminHapusUser();
void adminOrderUser();
void userSignUp();
void userLogin(int l);
void userMenu();
void userCheck();
void userSewaKendaraan();
void userHasilPesanan();

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
  printf(" [1] ADMIN \n");
  printf(" [2] USER   \n");
  printf(" [0] EXIT    \n");
  line();
  printf(" PILIH MENU : ");
  scanf("%d", &o);
  getchar();
  if (o == 1)
  {
    system("cls");
    adminLogin(3);
  }
  else if (o == 2)
  {
    system("cls");
    userCheck();
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
  printf(" [2] Input Kendaraan   \n");
  printf(" [3] List Kendaraan   \n");
  printf(" [4] Cari Akun User    \n");
  printf(" [5] Hapus Akun User    \n");
  printf(" [6] Orderan User    \n");
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
    ptr = fopen("BDrive-Listkendaraan.dat", "ab");
    printf(" Banyak kendaraan yang akan di tambahkan : ");
    scanf("%d", &o);
    getchar();
    for (i = 0; i < o; i++)
    {
      printf("\n %d. Jenis Kendaraan\t: ", i + 1);
      gets(kndr.jenis);
      printf("\n    Nama Kendaraan\t: ");
      gets(kndr.namakendaraan);
      printf("\n    Harga perhari\t: Rp. ");
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
    adminListKendaraan();
    break;
  case 4:
    system("cls");
    adminCariUser();
    break;
  case 5:
    system("cls");
    adminHapusUser();
    break;
  case 6:
    system("cls");
    adminOrderUser();
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

void adminListKendaraan()
{
  tampilan();
  printf("\t\t ADMIN - DAFTAR KENDARAAN \n\n");
  ptr = fopen("BDrive-Listkendaraan.dat", "rb");
  while (fread(&kndr, sizeof(kndr), 1, ptr) == 1)
  {
    s = i;
    temp[s] = kndr;
    i++;
  }
  for (s = i - 1; s >= 1; s--)
    for (j = 1; j <= s; j++)
    {
      if (temp[j - 1].perhari > temp[j].perhari)
      {
        temp2 = temp[j - 1];
        temp[j - 1] = temp[j];
        temp[j] = temp2;
      }
    }
  for (s = 0; s < i; s++)
  {
    printf("%d. Jenis Kendaraan\t: %s \n", s + 1, temp[s].jenis);
    printf("   Nama Kendaraan\t: %s \n", temp[s].namakendaraan);
    printf("   Harga Perhari\t: Rp. %d \n\n", temp[s].perhari);
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
    adminListKendaraan();
  }
}

void adminCariUser()
{
  tampilan();
  printf("\t\t ADMIN - CARI USER \n\n");
  printf("Masukan username dari user yang dicari : ");
  gets(find);
  ptr = fopen("BDrive-user.dat", "rb");
  while (fread(&user, sizeof(user), 1, ptr) == 1)
  {
    if (strcmp(user.username, find) == 0)
    {
      printf("\nUser yang dicari ditemukan");
      printf("\n\nNama     : %s\n", user.nama);
      printf("Username : %s\n", user.username);
    }
    else
    {
      printf("\nUser yang dicari tidak ditemukan!\n");
    }
    fclose(ptr);
    system("pause");
  }
  system("cls");
  adminMenu();
}

void adminHapusUser()
{
  tampilan();
  printf("\t\t ADMIN - HAPUS USER\n\n");
  ptr = fopen("BDrive-user.dat", "rb");
  ptr2 = fopen("temp.dat", "wb");
  printf("Masukan username yang akan dihapus : ");
  gets(find);
  while (fread(&user, sizeof(user), 1, ptr) == 1)
  {
    if (strcmp(user.username, find) != 0)
    {
      fwrite(&user, sizeof(user), 1, ptr2);
    }
    else
    {
      printf("\n user berhasil dihapus. \n\n");
    }
  }
  fclose(ptr);
  fclose(ptr2);
  remove("BDrive-user.dat");
  rename("temp.dat", "BDrive-user.dat");
  system("pause");
  system("cls");
  adminMenu();
}

void adminOrderUser()
{
  tampilan();
  printf("\t\t ADMIN - HASIL PESANAN \n\n");
  ptr = fopen("BDrive-user.dat", "rb+");
  ptr2 = fopen("BDrive-order.dat", "rb+");
  while (fread(&ordr, sizeof(ordr), 1, ptr2) == 1)
  {
    if (strcmp(ordr.nama, user.nama) == 0)
    {
      printf("Nama Pemesan\t\t\t: %s", ordr.nama);
      printf("\nNama Kendaraan\t\t\t: %s", ordr.namakendaraan);
      printf("\nNo. HP\t\t\t\t: %s", ordr.notel);
      printf("\nEmail\t\t\t\t: %s", ordr.email);
      printf("\nAlamat\t\t\t\t: %s", ordr.address);
      printf("\nJaminan\t\t\t\t: %s", ordr.jaminan);
      printf("\nTotal pembayaran\t\t: %d\n\n", total);
    }
    fclose(ptr);
    fclose(ptr2);
    system("pause");
    system("cls");
    userMenu();
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
    printf("Buat password\t: ");
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
  ptr2 = fopen("BDrive-userSignup.dat", "wb");
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
  ptr2 = fopen("BDrive-userSignup.dat", "rb");
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
  remove("BDrive-userSignup.dat");
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
  printf(" [1] Sewa Kendaraan \n");
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
    userSewaKendaraan();
    break;
  case 2:
    system("cls");
    userHasilPesanan();
    break;
  default:
    system("cls");
    main();
    break;
  }
}

void userSewaKendaraan()
{
  tampilan();
  printf("\t\t USER - SEWA KENDARAAN \n\n");
  ptr = fopen("BDrive-Listkendaraan.dat", "rb");
  while (fread(&kndr, sizeof(kndr), 1, ptr) == 1)
  {
    s = i;
    temp[s] = kndr;
    i++;
  }
  for (s = i - 1; s >= 1; s--)
    for (j = 1; j <= s; j++)
    {
      if (temp[j - 1].perhari > temp[j].perhari)
      {
        temp2 = temp[j - 1];
        temp[j - 1] = temp[j];
        temp[j] = temp2;
      }
    }
  for (s = 0; s < i; s++)
  {
    printf("%d. Jenis Kendaraan\t: %s \n", s + 1, temp[s].jenis);
    printf("   Nama Kendaraan\t: %s \n", temp[s].namakendaraan);
    printf("   Harga Perhari\t: Rp. %d \n\n", temp[s].perhari);
  }
  fclose(ptr);
  line();
  ptr = fopen("BDrive-ListKendaraan.dat", "rb+");
  order = fopen("BDrive-order.dat", "wb+");
  printf("Pilih nama kendaraan\t: ");
  fflush(stdin);
  gets(find);
  while (fread(&kndr, sizeof(kndr), 1, ptr) == 1)
  {
    if (strcmp(kndr.namakendaraan, find) == 0)
    {
      strcpy(find, ordr.namakendaraan);
      printf("Nama Pemesan\t\t: ");
      gets(kndr.nama);
      printf("No. HP\t\t\t: ");
      gets(kndr.notel);
      printf("Email\t\t\t: ");
      gets(kndr.email);
      printf("Alamat\t\t\t: ");
      gets(kndr.address);
      printf("Jumlah hari penyewaan\t: ");
      scanf("%d", &kndr.harisewa);
      getchar();
      printf("Jaminan\t\t\t: ");
      gets(kndr.jaminan);
      total = kndr.harisewa * kndr.perhari;
      printf("Total pembayaran\t: %d", total);
      printf("\n\nPESANAN BERHASIL!!!\n");
      fwrite(&kndr, sizeof(kndr), 1, order);
    }
    else
    {
      userMenu();
    }
    fclose(ptr);
    fclose(order);
    system("pause");
    system("cls");
    userMenu();
  }
}

void userHasilPesanan()
{
  tampilan();
  printf("\t\t USER - ORDER USER \n\n");
  ptr = fopen("BDrive-user.dat", "rb+");
  ptr2 = fopen("BDrive-order.dat", "rb+");
  while (fread(&ordr, sizeof(ordr), 1, ptr2) == 1)
  {
    if (strcmp(ordr.nama, user.nama) == 0)
    {
      printf("Nama Pemesan\t\t\t: %s", ordr.nama);
      printf("\nNama Kendaraan\t\t\t: %s", ordr.namakendaraan);
      printf("\nNo. HP\t\t\t\t: %s", ordr.notel);
      printf("\nEmail\t\t\t\t: %s", ordr.email);
      printf("\nAlamat\t\t\t\t: %s", ordr.address);
      printf("\nJaminan\t\t\t\t: %s", ordr.jaminan);
      printf("\nTotal pembayaran\t\t: %d\n\n", total);
    }
    fclose(ptr);
    fclose(ptr2);
    system("pause");
    system("cls");
    userMenu();
  }
}
