#include <stdio.h>     // Library standar untuk input/output file
#include <string.h>    // Library standar untuk manipulasi string
#include <stdlib.h>    // Library standar untuk operasi sistem seperti exit()
#include "deklarasi.h" // Include deklarasi struct dan prototype function

#define MAX_ALAT 100   // Maksimal jumlah data alat
#define MAX_PINJAM 100 // Maksimal jumlah data pinjaman

// ------------------- UTILITY FILE -------------------
// Function untuk membaca isi file alat.txt
int bacaAlat(AlatLab *list)
{
    FILE *file = fopen("alat.txt", "r"); // Buka file alat.txt untuk dibaca
    if (!file)
        return 0; // Jika file tidak ditemukan, kembalikan 0

    char buffer[100];
    fgets(buffer, sizeof(buffer), file); // Lewati baris header

    int i = 0;
    // Membaca setiap baris dan simpan ke struct AlatLab
    while (fscanf(file, "%u %s %s %s %u %u",
                  &list[i].id,
                  list[i].nama,
                  list[i].merek,
                  list[i].model,
                  &list[i].tahun,
                  &list[i].jumlah) == 6)
    {
        i++;
    }
    fclose(file); // Tutup file setelah selesai dibaca
    return i;     // Kembalikan jumlah alat yang berhasil dibaca
}

// Function untuk menulis ulang seluruh isi file alat.txt
void tulisAlat(AlatLab *list, int n)
{
    FILE *file = fopen("alat.txt", "w");
    if (!file)
    {
        printf("Gagal menulis ke file alat.txt\n");
        return;
    }

    fprintf(file, "%-5s %-20s %-20s %-20s %-10s %-10s\n",
            "id", "nama", "merek", "model", "tahun", "jumlah");

    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%-5u %-20s %-20s %-20s %-10u %-10u\n",
                list[i].id, list[i].nama, list[i].merek, list[i].model,
                list[i].tahun, list[i].jumlah);
    }
    fclose(file);
}