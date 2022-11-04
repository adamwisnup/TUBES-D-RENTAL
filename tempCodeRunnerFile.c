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
    main();
  }
}