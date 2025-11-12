
#include <stdio.h>     // Library standar untuk input/output
#include <string.h>    // Library untuk operasi string
#include <stdlib.h>    // Library untuk fungsi umum seperti exit()
#include "deklarasi.h" // Include deklarasi fungsi dari file header

// Fungsi untuk login berdasarkan username dan password
int login(const char *username, const char *password, char *role)
{
    FILE *file = fopen("akun.txt", "r"); // Buka file akun.txt dalam mode baca
    if (!file)
    {
        printf("File akun.txt tidak ditemukan.\n");
        return 0; // Gagal login jika file tidak ada
    }

    char fileUser[20], filePass[20], fileRole[20]; // Variabel sementara untuk membaca data dari file

    // Baca setiap baris dan bandingkan dengan input username dan password
    while (fscanf(file, "%s %s %s", fileUser, filePass, fileRole) == 3)
    {
        if (strcmp(username, fileUser) == 0 && strcmp(password, filePass) == 0)
        {
            strcpy(role, fileRole); // Simpan role pengguna (admin/user)
            fclose(file);
            return 1; // Login berhasil
        }
    }

    fclose(file);
    return 0; // Login gagal jika username/password tidak cocok
}