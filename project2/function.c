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

// Fungsi utama untuk membaca lirik, pisahkan kata, simpan ke file kosa-kata
void daftarKata(const char *inputFile, const char *outputFile)
{
    FILE *in = fopen(inputFile, "r");   // Membuka file input lirik
    FILE *out = fopen(outputFile, "w"); // Membuka file output kosa-kata

    if (in == NULL || out == NULL) // Cek apakah file berhasil dibuka
    {
        // Menampilkan pesan error jika file tidak berhasil dibuka
        printf("Gagal membuka file input atau output\n");
        printf("Silahkan ulangi lagi\n");
        return;
    }

    char judul[200];
    char baris[300];
    char daftar[500][50]; // Buffer kata unik, maksimal 500 kata
    int jumlahKata = 0;

    // Ambil baris pertama sebagai judul lagu dan tulis ke file output
    if (fgets(judul, sizeof(judul), in))
    {
        fprintf(out, "%s", judul);
    }

    // Baca sisa baris lirik
    while (fgets(baris, sizeof(baris), in))
    {
        char *token = strtok(baris, " \n\r\t"); // Memisahkan kata per kata
        while (token != NULL)
        {
            rapihinKata(token); // Membersihkan kata, hapus tanda baca dan lowercase kan kata
            if (strlen(token) > 0 && !cekKata(token, daftar, jumlahKata))
            {
                strcpy(daftar[jumlahKata++], token); // Menyimpan kata unik (kata yang hanya ditulis sekali saja)
                fprintf(out, "%s=\n", token);        // Menuliskan ke file
            }
            token = strtok(NULL, " \n\r\t"); // Lanjut ke kata berikutnya
        }
    }

    fclose(in);  // Tutup file input
    fclose(out); // Tutup file output
}
