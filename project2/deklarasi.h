#ifndef DEKLARASI_H // Include guard: mencegah header dibaca lebih dari sekali
#define DEKLARASI_H

void rapihinKata(char *kata);                                   // Function untuk membersihkan kata: hapus tanda baca & ubah ke huruf kecil
int cekKata(const char *kata, char daftar[][50], int jumlah);   // Function untuk cek apakah kata sudah ada di daftar
void daftarKata(const char *inputFile, const char *outputFile); // Function utama untuk membuat daftar kata unik dan menyimpan ke file

#endif // Penutup include guard

 

