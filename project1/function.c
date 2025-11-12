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
