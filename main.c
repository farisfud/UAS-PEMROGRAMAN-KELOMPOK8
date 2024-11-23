#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h> 
#include <io.h> 
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

typedef struct peserta {
    char username[50];
    char password[50]; 
} pengguna;

void cekdanmembuatFolder(const char *namaFolder) {
    // Mengecek apakah direktori sudah ada
    if (_access(namaFolder, 0) == 0) {
        printf("Folder '%s' sudah ada.\n", namaFolder);
    } else {
        // Jika direktori tidak ada, buat direktori baru
        if (_mkdir(namaFolder) == 0) {
            printf("Folder '%s' berhasil dibuat.\n", namaFolder);
        } else {
            perror("Gagal membuat folder");
        }
    }
}

void registrasiuser() {
    FILE *registrasi;
    pengguna user;

    // Cek apakah folder database sudah ada, jika belum buat
    cekdanmembuatFolder("database");

    registrasi = fopen("database/login.bin", "ab");  // Gunakan "ab" untuk append, bukan "wb"
    if (registrasi == NULL) {
        printf("Gagal membuka file database.\n");
        exit(1);
    }

    printf("\n === PROYEK PRAKTIKUM PEMROGRAMAN KELOMPOK 8 ===\n\n\n\n");
    printf("                  |REGISTRASI|                 \n\n");
    printf("  ===============================================\n");
    printf("  *                 PETUNJUK:                   *\n");
    printf("*  MASUKKAN USERNAME:   *\n");
    scanf("%s", user.username);
    printf("*  MASUKKAN PASSWORD:   *\n");
    scanf("%s", user.password);
    printf("   ==============================================\n\n");

    fwrite(&user, sizeof(pengguna), 1, registrasi);
    fclose(registrasi);

    printf("REGISTRASI BERHASIL! SILAHKAN LOGIN.\n");
}

int loginuser(char *username, char *password) {
    FILE *login;
    pengguna user;

    login = fopen("database/login.bin", "rb");
    if (login == NULL) {
        printf("Database tidak ditemukan, silakan registrasi terlebih dahulu.\n");
        exit(1);
    }

    while (fread(&user, sizeof(pengguna), 1, login)) {
        if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
            fclose(login);
            return 1;  // login berhasil
        }
    }

    fclose(login);
    return 0;  // login gagal
}



void soal_mudah(){
    int total_score = 0;
    char jawaban;

    printf ("\n*easy level*\n");
    printf ("\n---Selamat bermain!!---\n");

    //soal 1
    printf ("\n=====Soal 1=====\n");
    printf ("Di provinsi manakah pulau komodo terletak?\n");
    printf ("A. NTB\n");
    printf ("B. Jawa Barat\n");
    printf ("C. NTT\n");
    printf ("D. Bali\n");
    printf ("Pilih jawaban (A/B/C/D) : ");
    scanf ("%c", &jawaban);
    getchar(); // membaca atau membuang karakter yang tidak dibutuhkan
    if (jawaban == 'C'){
        print ("Yeyy!,jawaban anda benar!\n");
        total_score += 100;
    } 
    else {
        printf ("jawaban anda salah.\n");
    }

    //soal 2
    printf ("\n=====Soal 2=====\n");
    printf ("Apa julukan terkenal dari negara Korea Selatan?\n");
    printf ("A. Negeri Tirai Bambu\n");
    printf ("B. Negeri Kincir Angin\n");
    printf ("C. Zamrud Khatulistiwa\n");
    printf ("D. Negeri Gingseng\n");
    printf ("Pilih jawaban (A/B/C/D) : ");
    scanf ("%c", &jawaban);
    getchar();
    if (jawaban == 'D'){
        printf ("Horee!!, jawaban anda benar!\n");
        total_score += 100;
    }
    else {
        printf ("jawaban anda salah.\n");
    }

    //soal 3
    printf ("\n=====Soal 3=====\n");
    printf ("Negara manakah yang dijuluki Negara Gajah Putih?\n");
    printf ("A. Vietnam\n");
    printf ("B. Thailand\n");
    printf ("C. Brunei Darussalam\n");
    printf ("D. Myanmar\n");
    printf ("Pilih jawaban (A/B/C/D) : ");
    scanf ("%c", &jawaban);
    getchar();
    if (jawaban == 'B'){
        printf ("Mantap!, jawaban anda benar!\n");
        total_score += 100;
    }
    else {
        printf ("jawaban anda salah.\n");
    }

    //soal 4
    printf ("\n=====Soal 4=====\n");
    printf ("Benua manakah yang dijuluki Benua biru?\n");
    printf ("A. Eropa\n");
    printf ("B. Antartika\n");
    printf ("C. Australia\n");
    printf ("D. Amerika\n");
    printf ("Pilih jawaban (A/B/C/D) : ");
    scanf ("%c", &jawaban);
    getchar();
    if (jawaban == 'A'){
        printf ("Keren!!, jawaban anda benar!\n");
        total_score += 100;
    }
    else {
        printf ("jawaban anda salah.\n");
    }

    //soal 5
    printf ("\n=====Soal 5=====\n");
    printf ("\nApa nama bunga nasional Indonesia\n");
    printf ("A. Raflesia Arnoldi\n");
    printf ("B. Kenanga\n");
    printf ("C. Tulip\n");
    printf ("D. Melati\n");
    printf ("Pilih jawaban (A/B/C/D) : ");
    scanf ("%c", &jawaban);
    getchar();
    if (jawaban == 'D') {
        printf ("Hebat!, jawaban anda benar!\n");
        total_score += 100;
    }
    else {
        printf ("jawaban anda salah.\n");
    }

    //menampilkan hasil akhir
    printf ("Kuis telah selesai\n");
    printf ("Point akhir anda : %d point.\n", total_score);
    printf ("\nTerima Kasih sudah bermain!!\n");
}

int total_skor = 0;

void tampilkan_soal_void(int nomor_soal, const char *pertanyaan, const char *pilihan, char jawaban_benar, int batas_waktu) {
    char jawaban = '\0';
    int waktu_tersisa = batas_waktu;

    printf("\n===== SOAL %d =====\n", nomor_soal);
    printf("%s\n", pertanyaan);
    printf("%s\n", pilihan);

    while (waktu_tersisa > 0) {
        printf("\rWaktu tersisa: %d detik. Pilih jawaban (A/B/C/D): ", waktu_tersisa);
        fflush(stdout);

        Sleep(1000); 
        waktu_tersisa--;

        
        if (_kbhit()) {
            jawaban = getch(); 
            printf("%c\n", jawaban); 
            break;
        }
    }

    printf("\n");
    if (waktu_tersisa <= 0 && jawaban == '\0') {
        printf("Waktu habis! Anda melewati batas %d detik.\n", batas_waktu);
    } else if (jawaban == jawaban_benar) {
        printf("Jawaban benar!\n");
        total_skor += 20; 
    } else {
        printf("Jawaban salah. Jawaban yang benar adalah %c.\n", jawaban_benar);
    }
}


void soal_sulit() {
    int batas_waktu = 20;
    char lanjut;

    printf("===== KUIS PILIHAN GANDA =====\n");
    printf("Jawab pertanyaan berikut dengan memilih A, B, C, atau D.\n");
    printf("Anda memiliki waktu %d detik untuk setiap soal.\n", batas_waktu);

    tampilkan_soal_void(
        1,
        "Pergerakan nasional Indonesia pada awal abad ke-20 sangat dipengaruhi oleh berbagai faktor, baik internal maupun eksternal. Faktor eksternal yang paling dominan dalam memicu semangat nasionalisme di Indonesia adalah...",
        "A. Revolusi Perancis\nB. Perang Dunia I\nC. Revolusi Industri\nD. Perang Dingin",
        'B', batas_waktu
    );

    printf("Tekan Enter untuk melanjutkan ke soal berikutnya...\n");
    while ((lanjut = getch()) != '\r'); 

    tampilkan_soal_void(
        2,
        "Konsep adat istiadat dalam masyarakat Indonesia memiliki sifat yang dinamis. Hal ini berarti...",
        "A. Adat istiadat bersifat statis dan tidak berubah seiring waktu\nB. Adat istiadat selalu mengikuti perkembangan zaman dan teknologi\nC. Adat istiadat dapat beradaptasi dengan perubahan sosial dan budaya, namun tetap mempertahankan nilai-nilai dasarnya\nD. Adat istiadat hanya berlaku untuk masyarakat tradisional dan tidak relevan dengan masyarakat modern.",
        'C', batas_waktu
    );

    printf("Tekan Enter untuk melanjutkan ke soal berikutnya...\n");
    while ((lanjut = getch()) != '\r'); 

    tampilkan_soal_void(
        3,
        "Fenomena unik yang terjadi di Indonesia dan menjadi daya tarik bagi para peneliti adalah keberadaan garis Wallace dan Weber. Garis-garis ini membagi wilayah Indonesia menjadi beberapa zona biogeografi yang berbeda. Faktor utama yang menyebabkan perbedaan tersebut adalah...",
        "A. Iklim tropis\nB. Aktivitas vulkanik\nC. Sejarah geologis kepulauan\nD. Arus laut",
        'C', batas_waktu
    );

    printf("Tekan Enter untuk melanjutkan ke soal berikutnya...\n");
    while ((lanjut = getch()) != '\r'); 

    tampilkan_soal_void(
        4,
        "Salah satu faktor utama yang menyebabkan keragaman budaya di Indonesia adalah...",
        "A. Letak geografis yang berupa kepulauan\nB. Pengaruh agama yang beragam\nC. Adanya interaksi dengan berbagai bangsa asing\nD. Semua jawaban benar",
        'A', batas_waktu
    );

    printf("Tekan Enter untuk melanjutkan ke soal berikutnya...\n");
    while ((lanjut = getch()) != '\r'); 

    tampilkan_soal_void(
        5,
        "Manakah dari pernyataan berikut yang paling tepat menggambarkan hubungan antara kesenjangan sosial dan perubahan iklim...",
        "A. Kesenjangan sosial memperparah dampak perubahan iklim, terutama pada kelompok miskin, namun tidak terpengaruh olehnya\nB. Perubahan iklim memperbesar kesenjangan sosial, terutama di negara berkembang, namun tidak menyebabkan kesenjangan sosial\nC. Kesenjangan sosial dan perubahan iklim saling memperkuat, menciptakan lingkaran setan yang sulit diputus\nD. Kesenjangan sosial tidak terkait dengan perubahan iklim, keduanya merupakan masalah yang terpisah",
        'C', batas_waktu
    );

    printf("\nPoin akhir Anda: %d poin.\n", total_skor);
    if (total_skor >= 90) {
        printf("\nWAH NILAI ANDA SANGAT MEMUASKAN!\n");
    } else if (total_skor >= 70) {
        printf("\nNILAI ANDA BAGUS!\n");
    } else {
        printf("\nWADUH NILAI ANDA MASIH KURANG, TINGKATKAN LAGI!\n");
    }
    printf("ANDA SUDAH MENYELESAIKAN KUIS INI\n");
    printf("=== TERIMA KASIH ===\n");
}


void main_kuis() {
    soal_sulit();
}

int main() {
    main_kuis();
    return 0;
}



        
