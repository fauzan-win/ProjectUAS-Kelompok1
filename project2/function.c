#include <stdio.h>     // Library standar untuk input/output
#include <string.h>    // Library standar untuk manipulasi string
#include <ctype.h>     // Library standar untuk manipulasi karakter
#include "deklarasi.h" // Include deklarasi fungction

// Fungsi untuk menghapus tanda baca kecuali ' dan -, serta ubah huruf menjadi lowercase
void rapihinKata(char *kata)
{
    int i = 0, j = 0;
    while (kata[i] != '\0') // Loop sampai ketemu null terminator
    {
        if (isalpha(kata[i]) || kata[i] == '\'' || kata[i] == '-') // Hanya menyimpan huruf, ' dan -
        {
            kata[j++] = tolower(kata[i]); // Menyimpan karakter ke indeks j dan ubah ke lowercase
        }
        i++;
    }
    kata[j] = '\0'; // Akhiri string baru
}

// Fungsi untuk cek apakah kata sudah ada di daftar
int cekKata(const char *kata, char daftar[][50], int jumlah)
{
    for (int i = 0; i < jumlah; i++)
    {
        if (strcmp(daftar[i], kata) == 0) // Membandingkan kata dengan daftar
        {
            return 1; // Sudah ada
        }
    }
    return 0; // Belum ada
}
