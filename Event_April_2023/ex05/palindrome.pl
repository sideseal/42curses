#!/usr/bin/perl

use strict;
use warnings;

print "Enter a string: ";
my $input = <STDIN>;
chomp $input;

my $reverse_input = reverse $input;

if ($input eq $reverse_input) {
    print "The string is a palindrome!\n";
} else {
    print "The string is not a palindrome.\n";
}
