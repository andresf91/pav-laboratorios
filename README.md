# Uso de un Repositorio Git en GitHub

## Clonar un Repositorio
Para obtener una copia local de un repositorio alojado en GitHub, usar:
```sh
git clone git@github.com:andresf91/pav-laboratorios.git
```

## Agregar, Confirmar y Enviar Cambios
Después de realizar cambios en los archivos:

1. Agregar archivos al área de preparación:
```sh
git add .  # Agrega todos los cambios al barrer
git add archivo.ext  # Agrega un archivo en particular
git add src  # Agrega un directorio en particular
```

2. Confirmar los cambios con un mensaje:
```sh
git commit -m "Mensaje descriptivo del cambio"
```

3. Enviar los cambios al repositorio remoto:
```sh
git push origin main  # O la rama en la que estés trabajando, si no es main
```

## Obtener Cambios del Repositorio Remoto
Para actualizar tu copia local con los cambios del repositorio en GitHub:
```sh
git pull origin main
```

## Trabajar con Ramas
Crear una nueva rama:
```sh
git branch nombre-de-la-rama
```

Cambiar a la nueva rama:
```sh
git checkout nombre-de-la-rama
```

Subir la nueva rama a GitHub:
```sh
git push -u origin nombre-de-la-rama
```

## Editar en Codespaces
1. En GitHub, abrir el repositorio y hacer clic en el botón verde **"<>"**.
2. Seleccionar **"Codespaces"** y crear un nuevo espacio.
3. Editar los archivos directamente desde la interfaz de Visual Studio Code en el navegador.
4. Usar el terminal integrado para ejecutar comandos Git como `add`, `commit` y `push`.
5. Cuando se termina de hacer los cambios y quedan guardados, cerrar y eliminar el Codespace, así no te consume los minutos gratis mensuales.



