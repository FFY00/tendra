# TDF 4.1 Specification

The file def_4_1.db gives a compact machine readable description of the
encoding of TDF version 4.1, generated directly from the TDF specification.
The similar description for version 4.0, def_4_0.db, is also given.
The make_tdf tool may be used to generate code from these descriptions
and a template file; alternatively other tools may be written to process
the description.

The information given consists of:

 - the list of basic sorts [sorts],
 - the list of list sorts [lists],
 - the list of simple list sorts [slists],
 - the list of optional sorts [options],
 - the list of linkable sorts [linkable_entities],
 - the list of unit sorts [kinds_of_unit],
 - the list of edge constructs for linkable sorts [graph_edges],
 - the major version number [major_version],
 - the minor version number [minor_version].

Each sort has the following associated information:

 - the sort name [sortid],
 - the number of bits used to encode the sort [encoding_bits],
 - whether extended encoding is used [has_extension],
 - the list of constructs of that sort [constructs].

Each construct has the following associated information:

 - the construct name [construct_name],
 - the encoding of the construct [encoding],
 - the name of the construct result sort [result_sort],
 - the list of construct parameters [parameter_sorts],

it may also have:

 - a list of boundary alignment information [boundaries],
 - a list of parameter break information [break].

Each construct parameter has the following associated information:

 - the parameter name,
 - the name of the parameter sort.

The boundary alignment information gives a list of numbers which indicate
that the nth argument should be aligned on a byte boundary.  The parameter
break information is also a list of numbers which indicate that the value
of the construct needs to be partially evaluated after the nth argument
has been read.

Each list or simple list entry consists of a sort name with a '_list'
suffix.  Similarly each optional sort entry consists of a sort name
with an '_option' suffix.

Each linkable sort has the following associated information:

 - the sort name [entity_sort],
 - the name used to identify the sort in a TDF capsule [entity_identifier].

Each unit sort has the following associated information:

 - the sort name [unit_elements],
 - the name used to identify the sort in a TDF capsule [unit_identifier].

Each edge construct has the following associated information:

 - the result sort name [edge_sort],
 - the construct name [edge_construct].

For a formal grammar of the description file, see the sid grammar,
syntax.sid, in the make_tdf source.
