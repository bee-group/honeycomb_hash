from distutils.core import setup, Extension


honeycomb_hash_module = Extension('honeycomb_hash',
                               sources = ['honeycombmodule.c',
                                          'honeycomb.c',
										  'honeycomb/facet_one.c',
										  'honeycomb/facet_two.c',
										  'honeycomb/facet_three.c',
										  'honeycomb/facet_four.c',
										  'honeycomb/facet_five.c',
										  'honeycomb/facet_six.c'],
                               include_dirs=['.', './honeycomb'])

setup (name = 'hashs',
       version = '1.0',
       description = 'Binding for Beenode Honeycomb proof of work hashing.',
       ext_modules = [honeycomb_hash_module])
