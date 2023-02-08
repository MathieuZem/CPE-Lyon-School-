#version 330 core

out vec4 color;

in vec2 vtex;

uniform sampler2D t;
uniform int c;

void main (void)
{

  int ascii_offset = 32;                // ASCII code of 1st char in texture file is 32
  int width        = 30;                // 30 char per line in texture file
  float x_tick     = 0.0333f;           // .. so 1/30 char horizontally
  float y_tick     = 0.2f;              // And 1/5 char vertically

  int ascii_code      = c;                    			// Current char ASCII value
  int t_code    = ascii_code - ascii_offset;      	// Current char index in our texture
  float t_x = (t_code % width) * x_tick;    	// Current char horizontal position
  float t_y = int(t_code / width) * y_tick; 	// Current char vertical position

  vec2 tex_coord = vec2(t_x, t_y) + vtex * vec2(x_tick, y_tick) + vec2(0.0, 0.05);

  color = texture(t, tex_coord);
  if(length(color.xyz) < 0.1)
    discard;
}
