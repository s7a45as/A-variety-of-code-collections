package com.wu.idomwx.generator.dto;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Userreq {

    private String username;
    private String password;
    private String salt;


}
