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

// Function untuk membaca isi file pinjam.txt
int bacaPinjam(Pinjam *list)
{
    FILE *file = fopen("pinjam.txt", "r"); // Buka file pinjam.txt
    if (!file)
        return 0;

    char buffer[100];
    fgets(buffer, sizeof(buffer), file); // Lewati header

    int i = 0;
    // Baca data baris per baris ke struct Pinjam
    while (fscanf(file, "%s %u %u %s",
                  list[i].username,
                  &list[i].idAlat,
                  &list[i].jumlah,
                  list[i].tanggal) == 4)
    {
        i++;
    }
    fclose(file);
    return i;
}

// Function untuk menulis ulang file pinjam.txt
void tulisPinjam(Pinjam *list, int n)
{
    FILE *file = fopen("pinjam.txt", "w"); // Buka file untuk ditulis
    if (!file)
        return;

    fprintf(file, "username idAlat jumlah tanggal\n"); // Tulis header
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%s %u %u %s\n",
                list[i].username,
                list[i].idAlat,
                list[i].jumlah,
                list[i].tanggal);
    }
    fclose(file);
}

// Function untuk mengecek apakah ID alat sudah ada di list
int cekIdAlat(unsigned int id, AlatLab *list, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (list[i].id == id)
            return 1; // Jika ID ditemukan, return 1
    }
    return 0; // Jika belum ada, return 0
}

// ------------------- FUNCION ADMIN -------------------
// Function untuk menambah data alat baru
void tambahAlat()
{
    AlatLab list[MAX_ALAT], alat;
    int n = bacaAlat(list); // Baca data alat yang sudah ada

    printf("ID Alat baru: ");
    scanf("%u", &alat.id);

    // Cegah ID duplikat
    if (cekIdAlat(alat.id, list, n))
    {
        printf("ID %u sudah ada, program akan berhenti\n", alat.id);
        exit(1);
    }

    // Input data baru
    printf("Nama Alat: ");
    scanf("%s", alat.nama);
    printf("Merek: ");
    scanf("%s", alat.merek);
    printf("Model: ");
    scanf("%s", alat.model);
    printf("Tahun: ");
    scanf("%u", &alat.tahun);
    printf("Jumlah: ");
    scanf("%u", &alat.jumlah);

    // Simpan data baru ke list dan tulis ke file
    list[n++] = alat;
    tulisAlat(list, n);
    printf("Alat berhasil ditambahkan.\n");
}