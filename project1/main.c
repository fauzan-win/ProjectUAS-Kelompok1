
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


int main(int argc, char *argv[])
{
    // Validasi jumlah argumen. Harus ada 3 (program, username, password)
    if (argc != 3)
    {
        printf("Format: %s <username> <password>\n", argv[0]);
        printf("Contoh: %s admin admin123\n", argv[0]);
        return 1; // Program dihentikan jika format salah
    }

    char role[20]; // Variabel untuk menyimpan peran (admin/user)

    // Panggil fungsi login dan cek hasilnya
    if (!login(argv[1], argv[2], role))
    {
        printf("Login gagal. Username atau password salah.\n");
        return 1; // Program berhenti jika login gagal
    }

    // Jika login berhasil, tampilkan informasi role
    printf("\nLogin berhasil. Role: %s\n", role);
    printf("\033[1;34m=====================================\033[0m\n");

    // Arahkan ke menu sesuai role pengguna
    if (strcmp(role, "admin") == 0)
    {
        menuAdmin(); // Tampilkan menu admin
    }
    else if (strcmp(role, "user") == 0)
    {
        menuUser(argv[1]); // Tampilkan menu user berdasarkan username
    }
    else
    {
        printf("Role tidak dikenal. Program keluar.\n");
        printf("\033[1;34m=====================================\033[0m\n");
        return 1; // Hentikan program jika role tidak valid
    }

    return 0; 
}