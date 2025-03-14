# Image Processing Library

## Overview

This project is an **image processing library** that provides various functions for manipulating BMP images. It includes functionalities such as flipping, rotating, cropping, extending, pasting, and applying filters to images. The system is designed to handle **raw pixel data** in a structured manner, making it easy to perform transformations on images.

## Features

- **BMP File Handling**: Load and save images in BMP format.
- **Image Transformations**: Flip, rotate, crop, and extend images.
- **Image Composition**: Paste one image onto another at a specific position.
- **Filtering**: Apply convolution filters to modify image properties such as blurring, sharpening, or edge detection.

## Functions Implemented

### **flip_horizontal**
- Mirrors an image horizontally by swapping pixels from left to right across the center.

### **rotate_left**
- Rotates an image **90 degrees counterclockwise** by rearranging pixels in a new matrix.

### **crop**
- Extracts a specific rectangular region from an image using the provided coordinates `(x, y, width, height)`.

### **extend**
- Expands an image by adding a **colored border** around it with specified RGB values.

### **paste**
- Overlays one image onto another at a specific `(x, y)` position, ensuring proper boundary handling.

### **apply_filter**
- Uses a **convolution filter** to modify the image, enabling effects like blurring and sharpening.
