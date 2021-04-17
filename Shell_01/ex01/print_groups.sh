#!/bin/sh 
export FT_USER=staff
groups $FT_USER | tr ' ' ','
export FT_USER=student
groups $FT_USER | tr ' ' ',' | tr -d '\n'