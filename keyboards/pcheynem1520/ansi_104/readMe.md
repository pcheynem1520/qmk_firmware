Documentation: https://beta.docs.qmk.fm/

By PJCM

Created to function as a drop in replacement for an ANSI 104-key keyboard.
Additional QMK functionality is also implemented.

ansi_104.h: IN PROGRESS
	TODO
	1.	Define final pinout

ansi_104_r2: IN PROGRESS
	Added new matrix_scan_user() definition
		Currrently just matrix_scan() with extraneous #ifs removed and referencing read_cols_on_row_user
		read_cols_on_row_user() is currently identical to read_cols_on_row()
	TODO
	1.	Define final pinout config
	2.	Change matrix_scan_user() to work with I2C GPIO expander
	3.	Add bluetooth support
	4.	Add Logitech Unifying support?
	5.	Implement I2C to drive small OLED display to show keyboard status