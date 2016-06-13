{application,qr_server,
[{description, "QR project Resource Manager of seteda54"},
 {vsn, "1.0"},
 {modules, [qr_app,qr_db,qr_sup,qr_worker,user]},
 {registered,[qr_server,qr_sup,qr_worker]},
 {applications, [kernel,stdlib]},
 {mod,{qr_app,[]}},
 {start_phases, []}
]}.