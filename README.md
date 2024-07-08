
# Library dan Aplikasi NGRuat

Ruwatan memiliki arti "dilepas" atau "dibebaskan". Oleh karena itu, Ruwatan merupakan upacara yang bertujuan membebaskan seseorang yang diruwat dari hukuman atau kutukan dewa ataupun hutang piutang di kehidupan masa lalu yang membawa bahaya.

Library dan Aplikasi ini menyediakan fungsionalitas untuk membantu Manggalaning Upakara dalam pembuatan dokumen daftar Sarana Upacara yang harus disiapkan serta Mantra yang digunakan dalam pelaksanaan upacara Ruwatan tersebut. Dengan adanya library dan aplikasi ini, diharapkan dapat mempermudah tugas Pinandita/Pandita dalam menyusun Dokumen Sarana Upacara dan Mantra. Disamping itu, dengan didetailkannya daftar Sarana Upacara yang wajib disiapkan maka resiko adanya sarana yang terlewat dapat diminimalisir.

## Persiapan Installasi Library dan Aplikasi

Lakukan installasi paket-paket berikut.

### Installasi Compiller dan CMake

1. Installasi Compiler:

```bash
sudo apt install build-essential g++ binutils
```

3. Installasi CMake:

```bash
sudo apt install make cmake
```

### Installasi Dependency (Library)

```bash
sudo apt install libboost-system-dev libssl-dev zlib1g-dev libcurl4-openssl-dev libboost-test-dev libsqlite3-dev libboost-all-dev
```

### Installasi Google Test

1. Clone repository:

```bash
git clone https://github.com/google/googletest.git -b v1.14.0
```

2. Masuk ke directory dari repository yang sudah di-clone:

```bash
cd googletest
```

3. Compile Google Test Library:

```bash
mkdir build
cd build
cmake ..
make
```

4. Install Google Test Library:

```bash
sudo make install
```

5. Kembali ke root directory:

```bash
cd ../../
```

## Compile Library dan Aplikasi

1. Clone main repository:

```bash
git clone https://github.com/JayaWikrama/NGRuat.git
```

2. Pindah ke direktori proyek:

```bash
cd Balinese-Wariga
```

3. Buat direktori build:

```bash
mkdir build
cd build
```

4. Konfigurasi CMake:

```bash
cmake ..
```

5. Lakukan kompilasi:

```bash
make
```

6. Jalankan unit test untuk memastikan semua fungsi berjalan dengan normal:

```bash
./WarigaBali-test
```

Output hasil test:

```bash
[==========] Running 108 tests from 3 test suites.
[----------] Global test environment set-up.
[----------] 93 tests from DataTest
[ RUN      ] DataTest.DefaultConstructor1
[       OK ] DataTest.DefaultConstructor1 (0 ms)
[ RUN      ] DataTest.SetterAndGetter_0
[       OK ] DataTest.SetterAndGetter_0 (14 ms)
[ RUN      ] DataTest.SetterAndGetter_1
[       OK ] DataTest.SetterAndGetter_1 (8 ms)
[ RUN      ] DataTest.SetterAndGetter_2
[       OK ] DataTest.SetterAndGetter_2 (8 ms)
[ RUN      ] DataTest.SetterAndGetter_3
[       OK ] DataTest.SetterAndGetter_3 (8 ms)
....
....
....
[ RUN      ] RuwatanTest.SetterAndGetter_setupNegative3
[       OK ] RuwatanTest.SetterAndGetter_setupNegative3 (0 ms)
[ RUN      ] RuwatanTest.SetterAndGetter_setupNegative4
[       OK ] RuwatanTest.SetterAndGetter_setupNegative4 (0 ms)
[ RUN      ] RuwatanTest.SetterAndGetter_setupNegative5
[       OK ] RuwatanTest.SetterAndGetter_setupNegative5 (1 ms)
[----------] 8 tests from RuwatanTest (5 ms total)

[----------] Global test environment tear-down
[==========] 108 tests from 3 test suites ran. (677 ms total)
[  PASSED  ] 108 tests.
```

## Penggunaan

Aplikasi dapat dijalankan dengan perintah berikut:

```bash
./NGRuat <Telegram Bot Token>
```
