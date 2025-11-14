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

// ------------------- FUNGSI UTILITAS FILE -------------------
int bacaAlat(AlatLab *list);                          // Membaca data alat dari file dan menyimpannya ke array
void tulisAlat(AlatLab *list, int n);                 // Menulis seluruh data alat ke file
int bacaPinjam(Pinjam *list);                         // Membaca data peminjaman dari file
void tulisPinjam(Pinjam *list, int n);                // Menulis seluruh data peminjaman ke file
int cekIdAlat(unsigned int id, AlatLab *list, int n); // Mengecek apakah ID alat sudah ada

// ------------------- FUNGSI ADMIN -------------------
void tambahAlat(); // Menambah data alat baru ke sistem
void hapusAlat();  // Menghapus data alat dari sistem
void editAlat();   // Mengedit informasi alat yang sudah ada

// ------------------- FUNGSI VALIDASI -------------------
int validasiId(unsigned int id);          // Memastikan ID alat valid (unik dan positif)
int validasiTahun(unsigned int tahun);    // Memastikan tahun alat masuk dalam rentang wajar
int validasiJumlah(unsigned int jumlah);  // Memastikan jumlah alat valid (tidak negatif atau nol)
int validasiMenu(int pilihan, int batas); // Memastikan input menu berada dalam batas yang benar
int validasiString(const char *str);      // Memastikan string tidak kosong dan valid

// ------------------- FUNGSI USER -------------------
void lihatAlat();                          // Menampilkan daftar alat yang tersedia
void pinjamAlat(const char *username);     // Memproses peminjaman alat oleh user
void lihatPinjaman(const char *username);  // Menampilkan daftar alat yang sedang dipinjam oleh user
void kembalikanAlat(const char *username); // Memproses pengembalian alat oleh user

// ------------------- MENU -------------------
void menuAdmin(void);                // Menampilkan dan menangani menu khusus admin
void menuUser(const char *username); // Menampilkan dan menangani menu khusus user

#endif // Penutup include guard
