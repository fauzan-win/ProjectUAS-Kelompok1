#ifndef DEKLARASI_H // Include guard: mencegah header dibaca lebih dari sekali
#define DEKLARASI_H

// ------------------- STRUCT DATA -------------------
typedef struct
{
    unsigned int id;     // Meyimpan ID unik alat laboratorium
    char nama[250];      // Menyimpan nama alat
    char merek[250];     // Menyimpan nama merek alat
    char model[250];     // Menyimpan tipe atau model alat
    unsigned int tahun;  // Menyimpan tahun pembelian atau produksi alat
    unsigned int jumlah; // Menyimpan jumlah unit alat yang tersedia
} AlatLab;

typedef struct
{
    char username[20];   // Menyimpan nama pengguna yang meminjam alat
    unsigned int idAlat; // Menyimpan ID alat yang dipinjam
    unsigned int jumlah; // Menyimpan jumlah alat yang dipinjam
    char tanggal[20];    // Menyimpan tanggal peminjaman alat
} Pinjam;