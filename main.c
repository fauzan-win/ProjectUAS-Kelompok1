#include <stdio.h>     // Library standar untuk input/output
#include "deklarasi.h" // Include deklarasi function

int main()
{
    // Menampilkan pesan awal bahwa file sedang dibuat
    printf("Membuat daftar kosa kata dari lirik.txt...\n");

    // Panggil fungsi utama untuk membuat daftar kata unik dan simpan ke file
    daftarKata("lirik.txt", "kosa-kata.txt");

    // Menampilkan pesan bahwa file output berhasil dibuat
    printf("File kosa-kata.txt berhasil dibuat.\n");
    return 0; // Program selesai dengan sukses
}