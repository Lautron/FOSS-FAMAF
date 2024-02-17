# FOSS-FAMAF
## Programas para abrir archivos especiales
- .xmind: Xmind
- .xopp: Xournalpp
- .pmd: es lo mismo que markdown

## Como genero los pdf?
### .md
Usando pandoc.

Usar pandoc te permite utilizar LaTeX dentro de markdown, lo cual es mucho más
cómodo que usar solo LaTeX.

#### Comando
```bash
  pandoc --pdf-engine=xelatex -M documentclass=scrartcl -M numbersections=true --toc --toc-depth=4 -f markdown -t latex "ARCHIVO.md" -o "ARCHIVO.pdf"
```

### .xopp

```bash
xournalpp -p ARCHIVO.pdf ARCHIVO.xopp

```

### .xmind
No queda otra más que usar la interfaz grafica y exportar a pdf.
