#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para cifrar / descifrar byte a byte con XOR
int procesar_archivo(const char *origen, const char *destino, const char *clave) {
    FILE *f_origen = fopen(origen, "rb");
    if (!f_origen) return 0;

    FILE *f_destino = fopen(destino, "wb");
    if (!f_destino) {
        fclose(f_origen);
        return 0;
    }

    int byte_in, i = 0;
    int len_clave = strlen(clave);

    while ((byte_in = fgetc(f_origen)) != EOF) {
        fputc(byte_in ^ clave[i % len_clave], f_destino);
        i++;
    }

    fclose(f_origen);
    fclose(f_destino);
    return 1;
}

// Función auxiliar para imprimir el contenido del archivo en pantalla
void imprimir_archivo(const char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) return;

    int ch;
    while ((ch = fgetc(f)) != EOF) {
        putchar(ch);
    }
    fclose(f);
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Uso: %s <clave> <archivo_origen> <archivo_destino>\n", argv[0]);
        return 1;
    }

    char *clave = argv[1];
    char *origen = argv[2];
    char *destino = argv[3];

    // PASO 1: Crear archivo de prueba original con contenido
    FILE *f_test = fopen(origen, "w");
    if (f_test) {
        fputs("Hola Mundo FACU 2026", f_test);
        fclose(f_test);
    }

    printf("=== PASO 1: Texto Original ('%s') ===\n", origen);
    imprimir_archivo(origen);

    // PASO 2: Cifrar la primera vez
    if (!procesar_archivo(origen, destino, clave)) {
        printf("Error al cifrar el archivo.\n");
        return 1;
    }

    printf("\n=== PASO 2: Contenido Cifrado ('%s') ===\n", destino);
    imprimir_archivo(destino);

    // PASO 3: Pasarlo una segunda vez utilizando la misma clave (Descifrar)
    char descifrado_path[] = "resultado_descifrado.txt";
    if (!procesar_archivo(destino, descifrado_path, clave)) {
        printf("Error al descifrar el archivo.\n");
        return 1;
    }

    printf("\n=== PASO 3: Resultado de la Segunda Pasada ('%s') ===\n", descifrado_path);
    imprimir_archivo(descifrado_path);

    return 0;
}
