#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  clear_screen(s);
  color c;
  
  struct matrix *m2;
  struct matrix *m1;
  
  printf ("\n");
  printf ("Testing add_edge\nAdding (1, 2, 3), (4, 5, 6), m2 =\n");

  m2 = new_matrix (4, 2);
  add_edge (m2, 1, 2, 3, 4, 5, 6);
  print_matrix (m2);
  printf ("\n\n");
  
  printf ("Testing ident\nm1 =\n");
  
  m1 = new_matrix (4, 4);
  ident (m1);
  print_matrix (m1);
  printf ("\n\n");
  
  printf ("Testing matrix_mult\nm1 * m2 =\n");
  matrix_mult (m1, m2);
  print_matrix (m2);
  printf ("\n\n");
  
  printf ("Testing matrix_mult with new m1\nm1 =\n");
  free_matrix (m1);
  m1 = new_matrix (4, 4);
  add_edge (m1, 1, 2, 3, 4, 5, 6);
  add_edge (m1, 7, 8, 9, 10, 11, 12);
  print_matrix (m1);
  printf ("\n\n");
  
  printf ("m1 * m2 =\n");
  matrix_mult (m1, m2);
  print_matrix (m2);
  printf ("\n\n");
  
  free_matrix (m1);
  free_matrix (m2);
  
  printf ("Picture is being drawn...\n");
  
  c.red = 255;
  c.green = 255;
  c.blue = 255;
  
  struct matrix *rectangle;
  rectangle = new_matrix (4, 4);
  
  //main body
  add_edge (rectangle, 225, 450, 0, 275, 450, 0);
  add_edge (rectangle, 225, 150, 0, 275, 150, 0);
  add_edge (rectangle, 225, 450, 0, 225, 150, 0);
  add_edge (rectangle, 275, 450, 0, 275, 150, 0);
  
  //eraser top
  add_edge (rectangle, 225, 425, 0, 275, 425, 0);
  
  struct matrix *triangle;
  triangle = new_matrix (4, 4);
  
  //pencil head
  add_edge (triangle, 225, 150, 0, 250, 75, 0);
  add_edge (triangle, 275, 150, 0, 250, 75, 0);
  
  draw_lines (rectangle, s, c);
  draw_lines (triangle, s, c);
  display (s);
  save_extension (s, "pencil.png");
}  
